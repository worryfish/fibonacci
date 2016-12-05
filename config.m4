dnl
dnl $Id$
dnl

PHP_ARG_ENABLE(fibonacci, whether to enable fibonacci support,[ --enable-fibonacci   Enable fibonacci support])

if test "$PHP_FIBONACCI" = "yes"; then
  AC_DEFINE(HAVE_FIBONACCI, 1, [Whether you have FIBONACCI World])
  PHP_NEW_EXTENSION(fibonacci, fibonacci.c, $ext_shared)
fi
