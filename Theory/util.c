#include "util.h"

#include <stdio.h>
void print_debug(const char* format,...){
#if (DEBUG_print == 1)
	va_list l;
	va_start(l, format);
	vprintf(format, l);
	va_end(l);
#endif
}
