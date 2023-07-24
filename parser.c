#include "main.h"
#include <stdio.h>

/**
 * parser - produces a parse tree where code can be generated
 * @format: a string to be created
 * @func_list: an array
 * @elements: arguments list
 * Return: printed characters
 */

int parser(const char *format, conver_t func_list[], va_list elements)
{
	int idx_a, idx_b, output_val, num_printed;

	num_printed = 0;
	for (idx_a = 0; format[idx_a] != '\0'; idx_a++)
	{
		if (format[idx_a] == '%')
		{
			for (idx_b = 0; func_list[idx_b].sym != NULL; idx_b++)
			{
				if (format[idx_a + 1] == func_list[idx_b].sym[0])
				{
					output_val = func_list[idx_b].f(elements);
					if (output_val == -1)
						return (-1);
					num_printed += output_val;
					break;
				}
			}
			if (func_list[idx_b].sym == NULL
					&& format[idx_a + 1] != ' ')
			{
				if (format[idx_a + 1] != '\0')
				{
					_putchar(format[idx_a]);
					_putchar(format[idx_a + 1]);
					num_printed = num_printed + 2;
				}
				else
					return (-1);
			}
			idx_a = idx_a + 1;
		}
		else
		{
			_putchar(format[idx_a]);
			num_printed++;
		}
	}
	return (num_printed);
}
