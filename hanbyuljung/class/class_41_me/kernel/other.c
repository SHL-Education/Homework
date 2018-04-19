#include <linux/module.h>  /* Needed by all kernel modules */
#include <linux/kernel.h>  /* Needed for loglevels (KERN_WARNING, KERN_EMERG, KERN_INFO, etc.) */
#include <linux/init.h>    /* Needed for __init and __exit macros. */
#include <linux/moduleparam.h>
#include <linux/unistd.h>  /* sys_call_table __NR_* system call function indices */
#include <linux/fs.h>      /* filp_open */
#include <linux/slab.h>    /* kmalloc */

#include <asm/paravirt.h> /* write_cr0 */
#include <asm/uaccess.h>  /* get_fs, set_fs */
#include <linux/utsname.h>
#include <asm/cacheflush.h>
#include <linux/semaphore.h>

#define PROC_V    "/proc/version"
#define BOOT_PATH "/boot/System.map-"
#define MAX_VERSION_LEN   256
MODULE_LICENSE("GPL");
unsigned long *syscall_table = NULL;
asmlinkage int (*original_open)(const char *pathname, int flags, int mode);

asmlinkage int new_open(const char *pathname, int flags, int mode){
    printk(KERN_ALERT "[+] open() hooked.");
    return original_open(pathname, flags, mode);
}


static int find_sys_call_table (char *kern_ver) {
    char system_map_entry[MAX_VERSION_LEN];
    int i = 0;

    /*
     * Holds the /boot/System.map-<version> file name as we build it
     */
    char *filename;

    /*
     * Length of the System.map filename, terminating NULL included
     */
    size_t filename_length = strlen(kern_ver) + strlen(BOOT_PATH) + 1;

    /*
     * This will point to our /boot/System.map-<version> file
     */
    struct file *f = NULL;

    mm_segment_t oldfs;

    oldfs = get_fs();
    set_fs (KERNEL_DS);

    printk(KERN_EMERG "Kernel version: %s\n", kern_ver);

    filename = kmalloc(filename_length, GFP_KERNEL);
    if (filename == NULL) {
        printk(KERN_EMERG "kmalloc failed on System.map-<version> filename allocation");
        return -1;
    }

    /*
     * Zero out memory to be safe
     */
    memset(filename, 0, filename_length);

    /*
     * Construct our /boot/System.map-<version> file name
     */
    strncpy(filename, BOOT_PATH, strlen(BOOT_PATH));
    strncat(filename, kern_ver, strlen(kern_ver));

    /*
     * Open the System.map file for reading
     */
    f = filp_open(filename, O_RDONLY, 0);
    if (IS_ERR(f) || (f == NULL)) {
        printk(KERN_EMERG "Error opening System.map-<version> file: %s\n", filename);
        return -1;
    }
    memset(system_map_entry, 0, MAX_VERSION_LEN);

    /*
     * Read one byte at a time from the file until we either max out
     * out our buffer or read an entire line.
     */
    while (vfs_read(f, system_map_entry + i, 1, &f->f_pos) == 1) {
        /*
         * If we've read an entire line or maxed out our buffer,
         * check to see if we've just read the sys_call_table entry.
         */
        if ( system_map_entry[i] == '\n' || i == MAX_VERSION_LEN ) {
            // Reset the "column"/"character" counter for the row
            i = 0;

            if (strstr(system_map_entry, "sys_call_table") != NULL) {
                char *sys_string;
                char *system_map_entry_ptr = system_map_entry;

                sys_string = kmalloc(MAX_VERSION_LEN, GFP_KERNEL);  
                if (sys_string == NULL) { 
                    filp_close(f, 0);
                    set_fs(oldfs);

                    kfree(filename);

                    return -1;
                }

                memset(sys_string, 0, MAX_VERSION_LEN);

                strncpy(sys_string, strsep(&system_map_entry_ptr, " "), MAX_VERSION_LEN);

                //syscall_table = (unsigned long long *) kstrtoll(sys_string, NULL, 16);
                syscall_table = kmalloc(sizeof(unsigned long *), GFP_KERNEL);
                //syscall_table = kmalloc(sizeof(syscall_table), GFP_KERNEL);
                kstrtoul(sys_string, 16, syscall_table);
                printk(KERN_EMERG "syscall_table retrieved\n");

                kfree(sys_string);

                break;
            }

            memset(system_map_entry, 0, MAX_VERSION_LEN);
            continue;
        }

        i++;
    }

    filp_close(f, 0);
    set_fs(oldfs);

    kfree(filename);

    return 0;
}



static int __init moduleInit(void){
    find_sys_call_table(utsname()->release);
    printk(KERN_EMERG "Syscall table address: %p\n", syscall_table);
    if (syscall_table != NULL) {
        write_cr0 (read_cr0 () & (~ 0x10000));
        original_open = (void *)syscall_table[__NR_open];
        syscall_table[__NR_open] = &new_open;
        write_cr0 (read_cr0 () | 0x10000);
        printk(KERN_EMERG "[+] onload: sys_call_table hooked\n");
    } else {
        printk(KERN_EMERG "[-] onload: syscall_table is NULL\n");
    }
    return 0;
}

static void __exit moduleClear(void){
    if (syscall_table != NULL) {
        write_cr0 (read_cr0 () & (~ 0x10000));
        syscall_table[__NR_open] = &original_open;
        write_cr0 (read_cr0 () | 0x10000);
        printk(KERN_EMERG "[+] onunload: sys_call_table unhooked\n");
    } else {
        printk(KERN_EMERG "[-] onunload: syscall_table is NULL\n");
    }

}

module_init(moduleInit);
module_exit(moduleClear);
