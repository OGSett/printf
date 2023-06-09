#include "main.h"

/**
 * ex_print_all - function that handle S
 * a custom conversion specifier.
 * @list: list of args
 * @flags: pointer to flags.
 * @width: the width of the field.
 * @size: the size of type.
 * @precision: The field precision.
 * Return: number of char printed.
 */

int ex_print_all(va_list list, fl_t *flags, int width, int size, int precision)
{
	char *res;
	int count;

	(void)flags;
	(void)size;
	(void)width;
	(void)precision;

	res = va_arg(list, char *);
	if (res == NULL)
		return (putstr("(null)"));
	count = print_all(res);
	return (count);
}

/**
 * print_all - a function that print
 * printable and none printable chars.
 * @str: string to be printed
 * Return: number of char printed.
 */

int print_all(char *str)
{
	int i;
	int count;
	char *hex;

	i = 0;
	count = 0;
	while (str[i])
	{
		if ((str[i] > 0 && str[i] < 32) || str[i] >= 127)
		{
			count += putstr("\\x");
			hex = convert(str[i], 16, 1);
			if (hex[1] == '\0')
				count += _putchar('0');
			count += putstr(hex);
		}
		else
			count += _putchar(str[i]);
		i++;
	}
	return (count);
}

/**
 * print_address - handle and prints address
 * @list: list of arguments
 * @flags: pointer to flags
 * @width: the width of the field.
 * @size: the size of type.
 * @p: The field precision.
 * Return: nbr of printed characters
 */
int print_address(va_list list, fl_t *flags, int width, int size, int p)
{
	unsigned long int ptr;
	int count = 0, len, i;
	char *res;

	(void)flags;
	(void)size;
	(void)p;

	ptr = va_arg(list, unsigned long int);
	if (!ptr)
	{
		for (i = 0; i < (width - 5); i++)
			count += _putchar(' ');
		count += putstr("(nil)");
		return (count);
	}
	res = convert(ptr, 16, 0);
	len = _len(res) + 2;
	if (width > len)
	{
		for (i = 0; i < (width - len); i++)
			count += _putchar(' ');
	}
	count += putstr("0x");
	count += putstr(res);
	return (count);
}
