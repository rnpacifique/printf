#include <stdint.h>
#include "main.h"

/**
 * _printf - print formated output
 * @format: format string contain characters
 * Return: formated characters
 */
int _printf(const char *format, ...)
{
	int num_printed;

	conver_t func_list[] = {{"c", print_char}, {"s", print_string},
		{"%", print_percent}, {"d", print_int}, {"i", print_int}, {NULL, NULL}};

	va_list elements;

	if (format == NULL)
	{
		return (-1);
	}
	va_start(elements, format);

	num_printed = parser(format, func_list, elements);

	va_end(elements);
	return (num_printed);
}

