#!/usr/bin/env php
<?php

$start = microtime(true);

exec('php -d extension=/home/mbrzuchalski/Workspace/php-ext-console/modules/console.so php_console.php', $output, $code);

$finish = microtime(true);

print implode(PHP_EOL, $output) . PHP_EOL;

printf("\033[0;32mExecution time: \033[0;36m%0.4fs\033[0m\n", $finish - $start);
