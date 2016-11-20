<?php

$opt1 = new class implements \PHP\CLI\ParameterDefinition {
    public function getName() : string
    {
        return 'a';
    }
    public function isRequired() : bool
    {
        return true;
    }
};

$definitions = [
    $opt1,
//    new stdClass(),
];
$definition = new \PHP\CLI\CommandLineDefinition($definitions);

var_dump($definition);
