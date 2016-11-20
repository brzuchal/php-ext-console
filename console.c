/*
/+----------------------------------------------------------------------+
 | PHP CLI Console                                                      |
 +----------------------------------------------------------------------+
 | Copyright (c) 2016 Michał Brzuchalski                                |
 +----------------------------------------------------------------------+
 | This source file is subject to version 3.01 of the PHP license,      |
 | that is bundled with this package in the file LICENSE, and is        |
 | available through the world-wide-web at the following url:           |
 | http://www.php.net/license/3_01.txt.                                 |
 | If you did not receive a copy of the PHP license and are unable to   |
 | obtain it through the world-wide-web, please send a note to          |
 | license@php.net so we can mail you a copy immediately.               |
 +----------------------------------------------------------------------+
 | Author: Michał Brzuchalski <michal.brzuchalski@gmail.com>                |
 +----------------------------------------------------------------------+
*/
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "main/php_ini.h"
// #include "ext/standard/php_string.h"
// #include "ext/pcre/php_pcre.h"
#include "Zend/zend_operators.h"
#include "console.h"
#include "src/command_line_definition.c"
#include "src/parameter_definition.c"

// ZEND_DECLARE_MODULE_GLOBALS(console);

// static inline void php_console_init_globals(zend_console_globals *dsg) {
// 	memset(dsg, 0, sizeof(zend_console_globals));
// }

PHP_MINIT_FUNCTION(console)
{
	// ZEND_INIT_MODULE_GLOBALS(console, php_console_init_globals, NULL);

    // Interfaces
    php_register_parameter_definition();
    // php_ds_register_hashable();
    // php_ds_register_collection();
    // php_ds_register_sequence();

    // Classes
    php_register_command_line_definition();
    // php_ds_register_deque();
    // php_ds_register_stack();
    // php_ds_register_queue();
    // php_ds_register_map();
    // php_ds_register_set();
    // php_ds_register_priority_queue();
    // php_ds_register_pair();

    return SUCCESS;
}

PHP_RINIT_FUNCTION(console)
{
#if defined(COMPILE_DL_CONSOLE) && defined(ZTS)
    ZEND_TSRMLS_CACHE_UPDATE();
#endif

    return SUCCESS;
}

PHP_RSHUTDOWN_FUNCTION(console)
{
    return SUCCESS;
}

PHP_MINFO_FUNCTION(console)
{
    php_info_print_table_start();
    php_info_print_table_row(2, "console support", "enabled");
    php_info_print_table_row(2, "console version", PHP_CONSOLE_VERSION);
    php_info_print_table_end();
}

static const zend_module_dep console_deps[] = {
    ZEND_MOD_REQUIRED("pcre")
    ZEND_MOD_END
};

zend_module_entry console_module_entry = {
    STANDARD_MODULE_HEADER_EX,
    NULL,
    console_deps,
    "console",
    NULL,
    PHP_MINIT(console),
    NULL,
    PHP_RINIT(console),
    PHP_RSHUTDOWN(console),
    PHP_MINFO(console),
    PHP_CONSOLE_VERSION,
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_CONSOLE
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE();
#endif
ZEND_GET_MODULE(console)
#endif