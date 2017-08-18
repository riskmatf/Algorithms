#ifndef _UTIL_H_
#define _UTIL_H_

#define DEBUG_print 1 //you can set this to 0 if you do not want any printing on screen

#if (DEBUG_print == 1)
#include <stdarg.h>
#endif

/*Let there be colors
 * This set of function and constants allow 
 * users to manipulate terminal output a little bit
 * (ex: move curosr set foreground and backgrounds to predefined colors or rgb)
 * it is useful if you want nice output or something more complex like a progress bar in one line
 * color_bg_t and color_fg_t are used directly in printf if you want just put %s where you want to 
 * toggle some of the colors and then use the correct one*/

typedef enum color_t 
{
	BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN,	WHITE
}color_t;

#define BLACK_BG	("\x1b[40m")
#define RED_BG		("\x1b[41m")
#define GREEN_BG	("\x1b[42m")
#define YELLOW_BG	("\x1b[43m")
#define BLUE_BG		("\x1b[44m")
#define MAGENTA_BG	("\x1b[45m")
#define CYAN_BG		("\x1b[46m")
#define WHITE_BG	("\x1b[47m")
/*#define RGB_BG(val)\
	({\
		char s[50];\
		unsigned	r = (val & 0xFF0000u) >> 16,\
					g = (val & 0x00FF00u) >> 8,\
					b = (val & 0x0000FFu);\
		sprintf(s, "\x1b[48;2;%d;%d;%dm",r,g,b);\
		s;\
	})*/

#define BLACK_FG	("\x1b[30m")
#define RED_FG		("\x1b[31m")
#define GREEN_FG	("\x1b[32m")
#define YELLOW_FG	("\x1b[33m")
#define BLUE_FG		("\x1b[34m")
#define MAGENTA_FG	("\x1b[35m")
#define CYAN_FG		("\x1b[36m")
#define WHITE_FG	("\x1b[37m")
/*#define RGB_FG(val)\
	({\
		char s[51];\
		unsigned	r = (val & 0xFF0000) >> 16,\
					g = (val & 0x00FF00) >> 8,\
					b = (val & 0x0000FF);\
		sprintf(s, "\x1b[38;2;%d;%d;%dm",r,g,b);\
		s;\
	})*/
#define CLEAR_ATTRIBUTE ("\x1b[0m")

typedef enum attribute
{
	NONE = 0, BOLD = 1, UNDERLINE = 4
}attribute_t;

void set_color_fg(color_t c);
void set_color_bg(color_t c);
void set_color_pair(color_t fg, color_t bg);
void rgb_set_color_fg(unsigned rgb);
void rgb_set_color_bg(unsigned rgb);
void rgb_set_pair(unsigned rgb_fg, unsigned rgb_bg);
void clear_screen(void);
void clear_line(void);
void set_attribute(attribute_t a);
void clear_attribute(void);
void move_cursor(unsigned x, unsigned y);
void move_cursor_up(unsigned val);
void move_cursor_down(unsigned val);
void move_cursor_left(unsigned val);
void move_cursor_right(unsigned val);
void move_cursor_to_begin_of_line(void);
void print_debug(const char* format,...);

#endif
