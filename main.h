#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
/**
 * struct convert - creates a new type alias
 * @sym: string that represents format char specifier
 * @f: pointer
 */
struct convert
{
	char *sym;
	int (*f)(va_list);
};

typedef struct convert conver_t;

int _putchar(char c);
int _printf(const char *format, ...);
void _vprintf(const char *format, va_list elements);
int parser(const char *format, conver_t func_list[], va_list elements);
int printed_unsigned_number(unsigned int nbr);
int print_number(va_list elements);
int print_char(va_list elements);
int print_int(va_list elements);
int print_string(va_list elements);
int print_percent(va_list elements);

#endif

