#include "common.h"
#include "parameter_definition.h"

/* {{{ proto void ParameterDefinition::getName() : string
   Retrieve the parameter name */
ZEND_METHOD(ParameterDefinition, getName)
{
}
/* }}} */

/* {{{ proto void ParameterDefinition::isRequired() : bool
   Check the parameter is required */
ZEND_METHOD(ParameterDefinition, isRequired)
{
}
/* }}} */

void php_register_parameter_definition()
{
    zend_class_entry ce;
    zend_function_entry methods[] = {
        PHP_ABSTRACT_ME(ParameterDefinition, getName,    arginfo_parameter_definition_getName)
        PHP_ABSTRACT_ME(ParameterDefinition, isRequired, arginfo_parameter_definition_isRequired)
        PHP_FE_END
    };
    INIT_NS_CLASS_ENTRY(ce, CONSOLE_NS, "ParameterDefinition", methods);
    parameter_definition_ce = zend_register_internal_interface(&ce);
}