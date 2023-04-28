#include "main.h"

/**
 * _putchar - function that write char.
 * @c: char to be printed
 * Description: Use a local buffer of 1024 chars in order
 * to call write as little as possible.
 * Return: 1 if printed, -1 otherwise.
 */

int	_putchar(char c)
{
	static char BUFFER[SIZE_BUFFER];
	static int k;

	if (c == -1 || k == SIZE_BUFFER)
	{
		write(1, &BUFFER, k);
		k = 0;
	}
	if (c != -1)
	{
		if (k < SIZE_BUFFER)
		{
			BUFFER[k] = c;
			k++;
		}
		else
		{
			write(1, &BUFFER, k);
			k = 0;
			BUFFER[k] = c;
			k++;
		}
	}
	return (1);
}

/**
 * print_c - function that print one char.
 * @list: list of args.
 * @flags: pointer to flags.
 * @width: the width of the field.
 * @size: The size of type.
 * @precision: the field precision.
 * Return: 1 if printed, -1 otherwise.
 */

int print_c(va_list list, fl_t *flags, int width, int size, int precision)
{
	char c;
	int i, count = 0;

	(void)flags;
	(void)size;
	(void)precision;

	c = va_arg(list, int);
	if (width > 1)
	{
		for (i = 0; i < width - 1; i++)
			count += _putchar(' ');
	}
	count += _putchar(c);
	return (count);
}
/**
 * putstr - a function that print a string.
 * @str: string to be printed.
 * Return: number of printed char, -1 otherwise.
 */

int putstr(char *str)
{
	int i;
	int r_val = 0;

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
 * @flags: pointer to flags.
 * @width: the width of the field.
 * @size: The size of type.
 * @precision: The field precision.
 * Return: number of char printed, -1 otherwise.
 */

int print_s(va_list list, fl_t *flags, int width, int size, int precision)
{
	char *s;
	int len, i, count;

	count = 0;

	(void)flags;
	(void)size;
	(void)precision;
	s = va_arg(list, char *);
	if (s == NULL)
		s = "(null)";
	len = _len(s);
	if (width > len)
	{
		for (i = 0; i < (width - len); i++)
			count += _putchar(' ');
	}
	count += putstr(s);
	return (count);
}

/**
 * print_percent - function to print '%'.
 * @list: list of arg.
 * @flags: pointer to flags.
 * @width: the width of the field.
 * @size: the size of type.
 * @p: The field precision.
 * Return: 1 if printed, -1  otherwise.
 */

int print_percent(va_list list, fl_t *flags, int width, int size, int p)
{
	(void)list;
	(void)flags;
	(void)size;
	(void)width;
	(void)p;
	return (_putchar('%'));
}
