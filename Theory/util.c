#include "util.h"

#include <stdio.h>
#if (DEBUG_print == 1)
void print_debug(const char* format, ...){
	va_list l;
	va_start(l, format);
	vprintf(format, l);
	va_end(l);
}
#else
	void print_debug(const char * format, ...){}
#endif

void set_color_fg(color_t c)
{
	printf("\x1b[%dm", c+30);
}

void set_color_bg(color_t c)
{
	printf("\x1b[%dm", c+40);
}

void set_color_pair(color_t fg, color_t bg)
{
	printf("\x1b[%dm", fg+30);
	printf("\x1b[%dm", bg+40);
}

void rgb_set_color_fg(unsigned rgb)
{
	unsigned r,g,b;

	r = (rgb & 0xFF0000) >> 4;
	g = (rgb & 0x00FF00) >> 2;
	b = (rgb & 0x0000FF);

	printf("\x1b[38;2;%d;%d;%dm", r,g,b);
}

void rgb_set_color_bg(unsigned rgb)
{
	unsigned r,g,b;

	r = (rgb & 0xFF0000) >> 4;
	g = (rgb & 0x00FF00) >> 2;
	b = (rgb & 0x0000FF);

	printf("\x1b[48;2;%d;%d;%dm", r,g,b);

}

void rgb_set_pair(unsigned rgb_fg, unsigned rgb_bg)
{
	unsigned r,g,b;

	r = (rgb_fg & 0xFF0000) >> 4;
	g = (rgb_fg & 0x00FF00) >> 2;
	b = (rgb_fg & 0x0000FF);

	printf("\x1b[38;2;%d;%d;%dm", r,g,b);
	
	r = (rgb_bg & 0xFF0000) >> 4;
	g = (rgb_bg & 0x00FF00) >> 2;
	b = (rgb_bg & 0x0000FF);

	printf("\x1b[48;2;%d;%d;%dm", r,g,b);
}

void clear_screen(void)
{
	puts("\x1b[2J");
}

void clear_line(void)
{
	puts("\x1b[K");
}

void set_attribute(attribute_t a)
{
	printf("\x1b[%dm", a);
}

void clear_attribute(void)
{
	puts("\x1b[0m");
}

void move_cursor(unsigned x, unsigned y)
{
	printf("\x1b[%d;%dH", y, x);
}

void move_cursor_up(unsigned val)
{
	printf("\x1b[%dA", val);
}

void move_cursor_down(unsigned val)
{
	printf("\x1b[%dB", val);
}

void move_cursor_left(unsigned val)
{
	printf("\x1b[%dD", val);
}

void move_cursor_right(unsigned val)
{
	printf("\x1b[%dC", val);
}
