#include "main.h"

/**
 * print_number - print numbers
 * @elements: list of arguments
 * Return: length of arguments
 */
int print_number(va_list elements)
{
	int nbr;
	unsigned int n;
	int leng;
	int check;

	nbr = va_arg(elements, int);
	check = 1;
	leng = 0;

	if (nbr < 0)
	{
		leng = leng + _putchar('-');
		n = nbr * -1;
	}
	else
		n = nbr;
	for (; n / check > 9;)
		check *= 10;
	for (; check != 0;)
	{
		leng += _putchar('0' + n / check);
		n %= check;
		check /= 10;
	}
	return (leng);
}
/**
 * print_unsigned_number - print an unsigned number
 * @nbr: an unsigned number
 * Return: Number of chars printed.
*/
int print_unsigned_number(unsigned int nbr)
{
	int leng;
	int check;
	unsigned int n;

	leng = 0;
	check = 1;

	n = nbr;

	for (; n / check > 9;)
		check *= 10;
	for (; check != 0;)
	{
		leng = leng + _putchar('0' + n / check);
		n %= check;
		check /= 10;
	}
	return (leng);
}

/**
 * print_char - print characters
 * @elements: list of arguments
 * Return: char
 */

int print_char(va_list elements)
{
	char c;

	c = va_arg(elements, int);
	_putchar(c);
	return (1);
}

/**
 * print_int - print integer
 * @elements: list of argments
 * Return: int
 */

int print_int(va_list elements)
{
	int a;

	a = print_number(elements);
	return (a);
}

/**
 * print_percent - print %
 * @elements: list of argments
 * Return: '%'
 */

int print_percent(__attribute__((unused)) va_list elements)
{
	_putchar('%');
	return (1);
}

/**
 * print_string - print string
 * @elements: list of argments
 * Return: char
 */

int print_string(va_list elements)
{
	int a;
	const char *str;

	str = va_arg(elements, const char *);
	if (str == NULL)
	{
		str = "null";
	}
	for (a = 0; str[a] != '\0'; a++)
	{_putchar(str[a]);
	}
	return (a);

}



