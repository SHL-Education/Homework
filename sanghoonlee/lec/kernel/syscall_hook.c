#include <linux/kernel.h>
#include <linux/module.h>
#include <asm/unistd.h>
#include <linux/syscalls.h>
#include <linux/hugetlb.h>

unsigned long **sys_call_table;

unsigned long **locate_sys_call_table(void)
{
	unsigned long tmp;
	unsigned long *p;
	unsigned long **sys_table;

	for(tmp = 0xffffffff81000000; tmp < 0xffffffffa2000000; tmp += sizeof(void *))
	{
		p = (unsigned long *)tmp;
		if(p[__NR_close] == (unsigned long)sys_close)
		{
			sys_table = (unsigned long **)p;
			return &sys_table[0];
		}
	}

	return NULL;
}

asmlinkage long (* orig_call)(const char __user *, int, umode_t);

asmlinkage long sys_our_open(const char __user *filename, int flags, umode_t mode)
{
	printk("<0>Open System Call\n");
	return (orig_call(filename, flags, mode));
}

static int (*fixed_set_memory_rw)(unsigned long, int);

int syscall_hooking_init(void)
{
	unsigned long cr0;

	if((sys_call_table = locate_sys_call_table()) == NULL)
	{
		printk("<0>Can't find sys_call_table\n");
		return -1;
	}

	printk("<0>sys_call_table is at[%p]\n", sys_call_table);

	cr0 = read_cr0();
	write_cr0(cr0 & ~0x00010000);

	fixed_set_memory_rw = (void *)kallsyms_lookup_name("set_memory_rw");
	if(!fixed_set_memory_rw)
	{
		printk("<0>Unable to find set_memory_rw symbol\n");
		return 0;
	}

	fixed_set_memory_rw(PAGE_ALIGN((unsigned long)sys_call_table) - PAGE_SIZE, 3);

	orig_call = (void *)sys_call_table[__NR_open];
	sys_call_table[__NR_open] = (void *)sys_our_open;
	write_cr0(cr0);
	printk("<0>Hooking Success!\n");
	return 0;
}

void syscall_hooking_cleanup(void)
{
#if 1
	unsigned long cr0 = read_cr0();
	write_cr0(cr0 & ~0x00010000);
	sys_call_table[__NR_open] = orig_call;
	write_cr0(cr0);
	printk("<0>Module Cleanup\n");
#endif
}

module_init(syscall_hooking_init);
module_exit(syscall_hooking_cleanup);
MODULE_LICENSE("GPL");
