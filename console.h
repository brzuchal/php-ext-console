#ifndef PHP_CONSOLE_H
#define PHP_CONSOLE_H

// #include <stdbool.h>

#include "php.h"
#include "main/php.h"
// #include "zend_exceptions.h"
// #include "zend_interfaces.h"
// #include "zend_operators.h"
#include "ext/standard/info.h"
// #include "ext/standard/php_var.h"
// #include "ext/spl/spl_iterators.h"
// #include "ext/spl/spl_exceptions.h"
// #include "zend_smart_str.h"
// #include "ext/json/php_json.h"

extern zend_module_entry console_module_entry;

zend_class_entry *command_line_definition_ce;
zend_class_entry *parameter_definition_ce;

#define phpext_console_ptr &console_module_entry

/* Replace with version number for your extension */
#define PHP_CONSOLE_VERSION "0.0.1"

#ifdef PHP_WIN32
#  define PHP_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#  define PHP_API __attribute__ ((visibility("default")))
#else
#  define PHP_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

// ZEND_BEGIN_MODULE_GLOBALS(console)
// zend_fcall_info        user_compare_fci;
// zend_fcall_info_cache  user_compare_fci_cache;
// ZEND_END_MODULE_GLOBALS(console)

#ifdef ZTS
#define DSG(v) TSRMG(console_globals_id, zend_console_globals *, v)
#else
#define DSG(v) (console_globals.v)
#endif

// ZEND_EXTERN_MODULE_GLOBALS(console);

#if defined(ZTS) && defined(COMPILE_DL_CONSOLE)
ZEND_TSRMLS_CACHE_EXTERN();
#endif

#endif