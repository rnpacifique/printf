#include "main.h"

/**
 * _printf - print formated output
 * @format: format string conatain characters
 * Return: formated characters
 */


 int _printf(const char *format, ...)
{
	char buffer[BUFF_SIZE];
	int flags;
       	int width;
       	int size;
	int precision;
	int buff_index = 0;
	int a, printed = 0, all_chars = 0;
	va_list arguments;

	va_start(arguments, format)

	if (format == NULL)
	{
		return (-1);
	}
	for (a = 0; format && format[a] != '\0'; a++)
	{
		if (format(a) != '%')
		{
			buffer[buff_index++] = format[a];
			if (buff_index == BUFF_SIZE)
				print_buff(buffer, &buff_index);
			all_chars++;
		}
		else
		{
			print_buff(buffer, &buff_index);
			flags = get_flags(format, &a);
			width = get_width(format, &a, arguments);
			size = get_size(format, &a);
			precision = get_precision(format, &a, arguments);
			++a;

			printed = handle_print(format, &a, arguments, 
					buffer, flags, width, size, precision);
			if (prited == -1)
			{
				return (-1);
			}
			all_chars = all_chars + printed;
		}
	}

	print_buff(buffer, &buff_index);

	va_end(list);
	return(all_chars);
}
/**
 * print_buff - prints buffer if it is available
 * @buffer: sequence of chars
 * buff_index: Position for inserting the next character, indicating the length
 */
viod print_buff(char buffer[], int *buff_index)
{
	if (*buff_index > 0)
		write(1, &buffer[0], *buff_index);
	*buff_index = 0;
}
