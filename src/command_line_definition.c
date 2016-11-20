#include "common.h"
#include "command_line_definition.h"

/* {{{ proto void CommandLineDefinition::__construct(array $definitions)
   Create the CommandLineDefinition object */
ZEND_METHOD(CommandLineDefinition, __construct)
{
    zval *arr, *entry;
    zend_string *string_key;
    zend_ulong  option;

    // return_value = getThis();

    if (zend_parse_parameters(ZEND_NUM_ARGS(), "a", &arr) == FAILURE) {
        return;
    }

    ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(arr), option, string_key, entry) {
        if (string_key) {
            php_error_docref(NULL, E_WARNING,
                    "Array keys must be CURLOPT constants or equivalent integer values");
            RETURN_FALSE;
        }
        if (Z_TYPE_P(entry) != IS_OBJECT || !instanceof_function(Z_OBJCE_P(entry), parameter_definition_ce)) {
            php_error_docref(NULL, E_WARNING,
                    "Unexpected non parameter definition item given");
            RETURN_FALSE;
        }
    } ZEND_HASH_FOREACH_END();
    zend_update_property(command_line_definition_ce, getThis(), "definitions", sizeof("definitions")-1, arr);

    // zval tmp;
	// ZVAL_NULL(&tmp);
	// zend_update_property(command_line_definition_ce, getThis(), "definitions", sizeof("definitions"), &tmp);

    // zval definitions;
    // array_init(&definitions);
    // zend_declare_property(command_line_definition_ce, "definitions", sizeof("definitions")-1, &definitions, ZEND_ACC_PROTECTED);
}
/* }}} */

/* {{{ proto void CommandLineDefinition::hasArgumentDefinition(string $name) : bool
   Create the CommandLineDefinition object */
ZEND_METHOD(CommandLineDefinition, hasArgumentDefinition)
{
}
/* }}} */

/* {{{ proto void CommandLineDefinition::getArgumentDefinition(string $name) : ArgumentDefinition
   Create the CommandLineDefinition object */
ZEND_METHOD(CommandLineDefinition, getArgumentDefinition)
{
}
/* }}} */

/* {{{ proto void CommandLineDefinition::getArgumentDefinitionAtPosition(int $position) : ArgumentDefinition
   Create the CommandLineDefinition object */
ZEND_METHOD(CommandLineDefinition, getArgumentDefinitionAtPosition)
{
}
/* }}} */

/* {{{ proto void CommandLineDefinition::hasOptionDefinition(string $name) : OptionDefinition
   Create the CommandLineDefinition object */
ZEND_METHOD(CommandLineDefinition, hasOptionDefinition)
{
}
/* }}} */

/* {{{ proto void CommandLineDefinition::getOptionDefinition(string $name) : OptionDefinition
   Create the CommandLineDefinition object */
ZEND_METHOD(CommandLineDefinition, getOptionDefinition)
{
}
/* }}} */

void php_register_command_line_definition()
{
    zend_class_entry ce;
    zend_function_entry methods[] = {
        PHP_ME(CommandLineDefinition, __construct,                     arginfo_command_line_definition___construct,                     ZEND_ACC_CTOR|ZEND_ACC_PUBLIC)
        PHP_ME(CommandLineDefinition, hasArgumentDefinition,           arginfo_command_line_definition_hasArgumentDefinition,           ZEND_ACC_PUBLIC)
        PHP_ME(CommandLineDefinition, getArgumentDefinition,           arginfo_command_line_definition_getArgumentDefinition,           ZEND_ACC_PUBLIC)
        PHP_ME(CommandLineDefinition, getArgumentDefinitionAtPosition, arginfo_command_line_definition_getArgumentDefinitionAtPosition, ZEND_ACC_PUBLIC)
        PHP_ME(CommandLineDefinition, hasOptionDefinition,             arginfo_command_line_definition_hasOptionDefinition,             ZEND_ACC_PUBLIC)
        PHP_ME(CommandLineDefinition, getOptionDefinition,             arginfo_command_line_definition_getOptionDefinition,             ZEND_ACC_PUBLIC)
        PHP_FE_END
    };
    INIT_NS_CLASS_ENTRY(ce, CONSOLE_NS, "CommandLineDefinition", methods);
    command_line_definition_ce = zend_register_internal_class(&ce);
    zend_declare_property_null(command_line_definition_ce, "definitions", sizeof("definitions")-1, ZEND_ACC_PROTECTED);
}