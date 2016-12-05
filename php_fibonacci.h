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

#ifndef PHP_FIBONACCI_H
#define PHP_FIBONACCI_H 1
#define PHP_FIBONACCI_VERSION "1.0"
#define PHP_FIBONACCI_EXTNAME "Fibonacci"

PHP_FUNCTION(fibonacci);

size_t my_fibonacci_fast(size_t n);

extern zend_module_entry fibonacci_module_entry;
#define phpext_fibonacci_ptr &fibonacci_module_entry

#endif
