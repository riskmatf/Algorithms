#ifndef _UTIL_H_
#define _UTIL_H_

#define DEBUG_print 1 //you can set this to 0 if you do not want any printing on screen

#if (DEBUG_print == 1)
#include <stdarg.h>
#endif

void print_debug(const char* format,...);

#endif
