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
	{ 0xdd9fa878, "cdev_del" },
	{ 0x9330885b, "cdev_init" },
	{ 0xfbc74f64, "__copy_from_user" },
	{ 0x67c2fa54, "__copy_to_user" },
	{ 0x2e5810c6, "__aeabi_unwind_cpp_pr1" },
	{ 0xd8e484f0, "register_chrdev_region" },
	{ 0xb1ad28e0, "__gnu_mcount_nc" },
	{ 0x7485e15e, "unregister_chrdev_region" },
	{ 0xa173d1ae, "spi_setup" },
	{ 0xfa2a45e, "__memzero" },
	{ 0x27e1a049, "printk" },
	{ 0x42224298, "sscanf" },
	{ 0xfe617db, "driver_unregister" },
	{ 0x827fc0db, "spi_bus_type" },
	{ 0xf327507b, "spi_sync" },
	{ 0x20495cbb, "cdev_add" },
	{ 0xb81960ca, "snprintf" },
	{ 0x1df9e73f, "spi_register_driver" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "D2A00DB27B18B7B0215149D");
