#include "common.h"
#include "command_line_definition.h"

zend_class_entry *command_line_definition_ce;

// CommandLineDefinition::hasArgumentDefinition
// ZEND_BEGIN_ARG_INFO_EX(arginfo_command_line_definition_hasArgumentDefinition, 0, 0, 1)
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_command_line_definition_hasArgumentDefinition, 0, 1, _IS_BOOL, NULL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

// CommandLineDefinition::getArgumentDefinition
// ZEND_BEGIN_ARG_INFO_EX(arginfo_command_line_definition_getArgumentDefinition, 0, 0, 1)
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_command_line_definition_getArgumentDefinition, 0, 1, IS_OBJECT, CONSOLE_NS_NAME(ArgumentDefinition), 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

// CommandLineDefinition::getArgumentDefinitionAtPosition
ZEND_BEGIN_ARG_INFO_EX(arginfo_command_line_definition_getArgumentDefinitionAtPosition, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

// CommandLineDefinition::hasOptionDefinition
ZEND_BEGIN_ARG_INFO_EX(arginfo_command_line_definition_hasOptionDefinition, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

// CommandLineDefinition::getOptionDefinition
ZEND_BEGIN_ARG_INFO_EX(arginfo_command_line_definition_getOptionDefinition, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

void php_register_command_line_definition()
{
    zend_class_entry ce;
    zend_function_entry methods[] = {
        PHP_ABSTRACT_ME(CommandLineDefinition, hasArgumentDefinition, arginfo_command_line_definition_hasArgumentDefinition)
        PHP_ABSTRACT_ME(CommandLineDefinition, getArgumentDefinition, arginfo_command_line_definition_getArgumentDefinition)
        PHP_ABSTRACT_ME(CommandLineDefinition, getArgumentDefinitionAtPosition, arginfo_command_line_definition_getArgumentDefinitionAtPosition)
        PHP_ABSTRACT_ME(CommandLineDefinition, hasOptionDefinition, arginfo_command_line_definition_hasOptionDefinition)
        PHP_ABSTRACT_ME(CommandLineDefinition, getOptionDefinition, arginfo_command_line_definition_getOptionDefinition)
        PHP_FE_END
    };
    INIT_CLASS_ENTRY(ce, "PHP\\CLI\\CommandLineDefinition", methods);
    command_line_definition_ce = zend_register_internal_interface(&ce);
}