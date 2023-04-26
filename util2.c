#include "main.h"

/**
 * print_b - function that convert and print from
 * int to binary.
 * @list: list of args.
 * @flags: pointer to flags.
 * @width: the width of the field.
 * @size: size of type
 * Return: number of char printed.
 */
int print_b(va_list list, fl_t *flags, int width, int size)
{
	char *res;
	unsigned int input;
	int count;

	/* we will not use flags on custom specifier */
	(void)flags;
	(void)size;
	(void)width;

	input = va_arg(list, unsigned int);
	res = convert(input, 2, 0);
	count = putstr(res);
	return (count);
}

/**
 * print_uint - function that print unsigned int
 * @list: list of args.
 * @flags: pointer to flags.
 * @width: the width of the field.
 * @size: the size of type
 * Return: number of char printed.
 */

int print_uint(va_list list, fl_t *flags, int width, int size)
{
	unsigned long int input;
	char *res;
	int count = 0;
	int i;
	int len;
	unsigned long int converted;
	char padding = ' ';

	if (flags->zero)
		padding = '0';


	input = va_arg(list, unsigned long int);
	converted = convert_unsigned_number(input, size);
	res = convert(converted, 10, 0);
	len = _len(res);
	if (width > len /*&& !flags->zero*/)
	{
		for (i = 0; i < (width - len); i++)
			count += _putchar(padding);
	}
	count += putstr(res);
	return (count);
}

/**
 * print_octal - function that convert and print
 * from int to octal
 * @list: list of args.
 * @flags: pointer to flags.
 * @width: the width of the field.
 * @size: the size of type
 * Return: number of char printed.
 */

int print_octal(va_list list, fl_t *flags, int width, int size)
{
	unsigned long int input;
	char *res;
	int count = 0;
	int i;
	int len;
	unsigned long int converted;
	char padding = ' ';

	if (flags->zero)
		padding = '0';

	input = va_arg(list, unsigned long int);
	converted = convert_unsigned_number(input, size);
	res = convert(converted, 8, 0);
	len = _len(res);
	if (flags->hash == 1 && input != 0)
		len++;
	if (width > len /*+ 1 && !flags->zero*/)
	{
		for (i = 0; i < (width - len /*- 1*/); i++)
			count += _putchar(padding);
	}
	if (flags->hash == 1 && input != 0)
		count += _putchar('0');
	count += putstr(res);
	return (count);
}

/**
 * print_hex_lower - function that convert and print
 * from int to hex in lowercase.
 * @list: list of args.
 * @flags: pointer to flags.
 * @width: the width of the field.
 * @size: the size of type.
 * Return: number of char printed,
 */

int print_hex_lower(va_list list, fl_t *flags, int width, int size)
{
	unsigned long int input;
	char *res;
	int count = 0;
	int len, i;
	unsigned long int converted;
	char padding = ' ';

	if (flags->zero)
		padding = '0';

	input = va_arg(list, unsigned long int);
	converted = convert_unsigned_number(input, size);
	res = convert(converted, 16, 0);
	len = _len(res);
	if (flags->hash == 1 && input != 0)
		len += 2;
	if (width > len /*+ 2 && !flags->zero*/)
	{
		for (i = 0; i < (width - len /*- 2*/); i++)
			count += _putchar(padding);
	}
	if (flags->hash == 1 && input != 0)
		count += putstr("0x");
	count += putstr(res);
	return (count);
}

/**
 * print_hex_upper - function that convert and print from
 * int to hex in uppercase.
 * @list: list of args
 * @flags: pointer to flags.
 * @width: the width of the field.
 * @size: The size of type.
 * Return: number of chars printed.
 */
int print_hex_upper(va_list list, fl_t *flags, int width, int size)
{
	unsigned long int input;
	char *res;
	int count = 0;
	int len, i;
	unsigned long int converted;
	char padding = ' ';

	if (flags->zero)
		padding = '0';

	input = va_arg(list, unsigned long int);
	converted = convert_unsigned_number(input, size);
	res = convert(converted, 16, 1);
	len = _len(res);
	if (flags->hash == 1 && input != 0)
		len += 2;
	if (width > len /*+ 2 && !flags->zero*/)
	{
		for (i = 0; i < (width - len /*- 2*/); i++)
			count += _putchar(padding);
	}
	if (flags->hash == 1 && input != 0)
		count += putstr("0X");
	count += putstr(res);
	return (count);
}
