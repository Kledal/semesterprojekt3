#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
 .name = KBUILD_MODNAME,
 .init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
 .exit = cleanup_module,
#endif
 .arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xaa8a822b, "module_layout" },
	{ 0x6bc3fbc0, "__unregister_chrdev" },
	{ 0xbf8290d4, "cdev_alloc" },
	{ 0xdd9fa878, "cdev_del" },
	{ 0x9330885b, "cdev_init" },
	{ 0x2e5810c6, "__aeabi_unwind_cpp_pr1" },
	{ 0xdee5b14, "device_destroy" },
	{ 0xb1ad28e0, "__gnu_mcount_nc" },
	{ 0x91715312, "sprintf" },
	{ 0x27e1a049, "printk" },
	{ 0x11a13e31, "_kstrtol" },
	{ 0x6a44bb49, "device_create" },
	{ 0x20495cbb, "cdev_add" },
	{ 0xa9da9c49, "class_destroy" },
	{ 0x8c19e5ba, "__class_create" },
	{ 0x29537c9e, "alloc_chrdev_region" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "53B5C67AD8F7137EB1AF037");
