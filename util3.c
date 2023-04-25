#include "main.h"

/**
 * ex_print_all - function that handle S
 * a custom conversion specifier.
 * @list: list of args
 * @flags: pointer to flags.
 * @size: the size of type.
 * Return: number of char printed.
 */

int ex_print_all(va_list list, fl_t *flags, int size)
{
	char *res;
	int count;

	/* we will not use flags */
	(void)flags;
	(void)size;

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
 * @size: the size of type.
 * Return: nbr of printed characters
 */
int print_address(va_list list, fl_t *flags, int size)
{
	unsigned long int ptr;
	int count = 0;
	char *res;

	/* we will not use flags */
	(void)flags;
	(void)size;

	ptr = va_arg(list, unsigned long int);
	if (!ptr)
		return (putstr("(nil)"));
	res = convert(ptr, 16, 0);
	count += putstr("0x");
	count += putstr(res);
	return (count);
}
