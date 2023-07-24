#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

struct convert
{
        chae *sym;
        int (*f)(va_list);
};
typedef struct convert conver_t;

int _putchar(char c);
int _printf(const char *format, ...);
void _vprintf(const char *format, va_list elements);
int parser(const char *format, conver_t func_list[], va_list elements);
int printed_unsigned_number(unsigned int n);
int print_number(va_list);
int p_char(va_list);
int p_integer(va_list);
int p_string(va_list elements);
int p_percent(va_list);

#endif

