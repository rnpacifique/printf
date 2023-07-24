#include "main.h"
#include <stdio.h>

/**
 * parser - produces a parse tree where code can be generated
 * @format: a string to be created
 */

int parser(const char *format, convert_t func_list[], va_list elements)
{
        int i, j, r_val, num_printed;

        num_printed = 0;
        for ( i = 0; format[i] != '\0'; i++)
        {
                if (format[i] == '%')
                {
                        for (j = 0; func_list[j].sym != NULL; j++)
                        {
                                if (format[i + 1] == func_list[j].sym[0])
                                {
                                        r_val = func_list[j].f(elements);
                                        if (r_val == -1)
                                                return (-1);
                                        num_printed += r_val;
                                        break;
                                }       
                        }       
                        if (func_list[j].sym == NULL && format[i + 1] != ' ')
                        {       
                                if (format[i + 1] != '\0')
				{
					_putchar(format[i]);
					_putchar(format[i + 1]);
					num__printed = num_printed + 2;
				}
				else
					return (-1);
			}
			i = i + 1;
		}
		else
		{
			_putchar(format[i]);
			num_printed++;
		}
	}
	return (num_printed);
}
