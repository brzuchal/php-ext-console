PHP_ARG_ENABLE(CONSOLE, whether to enable console support,
[ --enable-console   Enable console support])

    AC_MSG_CHECKING([for PCRE headers location])
    for i in  /usr/include /usr/include/pcre /usr/local/include; do
      test -f $i/pcre.h && PCRE_INCDIR=$i
    done

    if test -z "$PCRE_INCDIR"; then
      AC_MSG_ERROR([Could not find pcre.h in $PHP_PCRE_REGEX])
    fi
    AC_MSG_RESULT([$PCRE_INCDIR])

if test "$PHP_CONSOLE" = "yes"; then
  AC_DEFINE(HAVE_CONSOLE, 1, [console])
  PHP_NEW_EXTENSION(console, console.c, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
fi