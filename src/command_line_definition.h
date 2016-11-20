#ifndef PHP_COMMAND_LINE_DEFINITION_H
#define PHP_COMMAND_LINE_DEFINITION_H

// CommandLineDefinition::__construct
ZEND_BEGIN_ARG_INFO_EX(arginfo_command_line_definition___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, definitions, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

// CommandLineDefinition::hasArgumentDefinition
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_command_line_definition_hasArgumentDefinition, 0, 1, _IS_BOOL, NULL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

// CommandLineDefinition::getArgumentDefinition
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_command_line_definition_getArgumentDefinition, 0, 1, IS_OBJECT, CONSOLE_NS_NAME(ArgumentDefinition), 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

// CommandLineDefinition::getArgumentDefinitionAtPosition
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_command_line_definition_getArgumentDefinitionAtPosition, 0, 1, IS_OBJECT, CONSOLE_NS_NAME(ArgumentDefinition), 1)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

// CommandLineDefinition::hasOptionDefinition
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_command_line_definition_hasOptionDefinition, 0, 1, _IS_BOOL, NULL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

// CommandLineDefinition::getOptionDefinition
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_command_line_definition_getOptionDefinition, 0, 1, IS_OBJECT, CONSOLE_NS_NAME(OptionDefinition), 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

#endif