/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2016 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: Breeze <breeze@worryfish.com>                                |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include "php.h"
#include "php_fibonacci.h"

static zend_function_entry fibonacci_functions[] = {
    PHP_FE(fibonacci, NULL)
    PHP_FE_END
};

zend_module_entry fibonacci_module_entry = {
    STANDARD_MODULE_HEADER,
    PHP_FIBONACCI_EXTNAME,
    fibonacci_functions,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    PHP_FIBONACCI_VERSION,
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_FIBONACCI
ZEND_GET_MODULE(fibonacci)
#endif

size_t my_fibonacci_fast(size_t n)
{
   size_t a = 0;
   size_t b = 1;
   size_t i;
   size_t sum = 0;
   
   for (i=0; i<n; i++) {
       sum = a + b;
       a = b;
       b = sum;
   }
   
   return a;
} 

PHP_FUNCTION(fibonacci)
{
    zend_long count_number;
    
    if (zend_parse_parameters(ZEND_NUM_ARGS(), "l", &count_number) == FAILURE) {
        return;
    }
    
    if ( count_number < 0 ) {
        php_error_docref(NULL, E_WARNING, "expects parameter 1 (%i) to be positive integer", count_number);
        RETURN_FALSE;
    }
    
    if ( count_number > 92 ) {
        php_error_docref(NULL, E_WARNING, "expects parameter 1 (%i) to be less than 93. Out of range PHP_INT_MAX", count_number);
        RETURN_FALSE;
    }
    
    RETURN_LONG( my_fibonacci_fast( count_number ) );
}
