#ifndef PHP_PARAMETER_DEFINITION_H
#define PHP_PARAMETER_DEFINITION_H

// ParameterDefinition::getName
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_parameter_definition_getName, 0, 0, IS_STRING, NULL, 0)
ZEND_END_ARG_INFO()

// ParameterDefinition::isRequired
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_parameter_definition_isRequired, 0, 0, _IS_BOOL, NULL, 0)
ZEND_END_ARG_INFO()

#endif