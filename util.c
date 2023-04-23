#include "main.h"

/**
 * _putchar - function that write char.
 * @c: char to be printed.
 * Return: 1 if printed, -1 otherwise.
 */

int	_putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_c - function that print one char.
 * @list: list of args.
 * Return: 1 if printed, -1 otherwise.
 */

int print_c(va_list list)
{
	char c;

	c = va_arg(list, int);
	return (_putchar(c));
}

/**
 * putstr - a function that print a string.
 * @str: string to be printed.
 * Return: number of printed char, -1 otherwise.
 */

int putstr(char *str)
{
	int i, r_val = 0;

	i = 0;
	while (str[i])
	{
		r_val += _putchar(str[i]);
		i++;
	}
	return (r_val);
}

/**
 * print_s - a function that write a string.
 * @list:  list of args.
 * Return: number of char printed, -1 otherwise.
 */

int print_s(va_list list)
{
	char *s;

	s = va_arg(list, char *);
	if (s == NULL)
		s = "(null)";
	return (putstr(s));
}

/**
 * print_percent - function to print '%'.
 * @list: list of arg.
 * Return: 1 if printed, -1  otherwise.
 */

int print_percent(va_list list)
{
	(void)list;
	return (_putchar('%'));
}
