#include "main.h"

/**
 * print_b - function that convert and print from
 * int to binary.
 * @list: list of args.
 * @flags: pointer to flags.
 * @width: the width of the field.
 * @size: size of type.
 * @precision: the field precision.
 * Return: number of char printed.
 */
int print_b(va_list list, fl_t *flags, int width, int size, int precision)
{
	char *res;
	unsigned int input;
	int count;

	(void)flags;
	(void)size;
	(void)width;
	(void)precision;

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
 * @size: the size of type.
 * @precision: the field precision.
 * Return: number of char printed.
 */

int print_uint(va_list list, fl_t *flags, int width, int size, int precision)
{
	unsigned long int input;
	char *res;
	int count = 0;
	int len;
	unsigned long int converted;
	char padding = ' ';

	if (flags->zero)
		padding = '0';
	input = va_arg(list, unsigned long int);
	if (flags->precision && !precision && input == 0)
		return (0);
	converted = convert_unsigned_number(input, size);
	res = convert(converted, 10, 0);
	len = _len(res);
	if (flags->precision && len < precision && precision > 0)
	{
		res = add_precision(res, len, precision);
		len = _len(res);
	}
	if (!flags->minus)
		count += write_padding(width, len, padding);
	count += putstr(res);
	if (flags->minus && padding != '0')
		count += write_padding(width, len, padding);
	return (count);
}

/**
 * print_octal - function that convert and print
 * from int to octal
 * @list: list of args.
 * @flags: pointer to flags.
 * @width: the width of the field.
 * @size: the size of type
 * @precision: The field precision.
 * Return: number of char printed.
 */

int print_octal(va_list list, fl_t *flags, int width, int size, int precision)
{
	unsigned long int input;
	char *res;
	int count = 0;
	int len;
	unsigned long int converted;
	char padding = ' ';

	(void)precision;
	if (flags->zero)
		padding = '0';
	input = va_arg(list, unsigned long int);
	converted = convert_unsigned_number(input, size);
	res = convert(converted, 8, 0);
	len = _len(res);
	if (flags->hash == 1 && input != 0)
		len++;
	if (!flags->minus)
		count += write_padding(width, len, padding);
	if (flags->hash == 1 && input != 0)
		count += _putchar('0');
	count += putstr(res);
	if (flags->minus && padding != '0')
		count += write_padding(width, len, padding);
	return (count);
}

/**
 * print_hex_lower - function that convert and print
 * from int to hex in lowercase.
 * @list: list of args.
 * @flags: pointer to flags.
 * @width: the width of the field.
 * @size: the size of type.
 * @p: the field precision.
 * Return: number of char printed,
 */

int print_hex_lower(va_list list, fl_t *flags, int width, int size, int p)
{
	unsigned long int input;
	char *res;
	int count = 0;
	int len;
	unsigned long int converted;
	char padding = ' ';

	(void)p;
	if (flags->zero)
		padding = '0';
	input = va_arg(list, unsigned long int);
	converted = convert_unsigned_number(input, size);
	res = convert(converted, 16, 0);
	len = _len(res);
	if (flags->hash == 1 && input != 0)
		len += 2;
	if (!flags->minus)
		count += write_padding(width, len, padding);
	if (flags->hash == 1 && input != 0)
		count += putstr("0x");
	count += putstr(res);
	if (flags->minus && padding != '0')
		count += write_padding(width, len, padding);
	return (count);
}

/**
 * print_hex_upper - function that convert and print from
 * int to hex in uppercase.
 * @list: list of args
 * @flags: pointer to flags.
 * @width: the width of the field.
 * @size: The size of type.
 * @p: The field precision.
 * Return: number of chars printed.
 */
int print_hex_upper(va_list list, fl_t *flags, int width, int size, int p)
{
	unsigned long int input;
	char *res;
	int count = 0;
	int len;
	unsigned long int converted;
	char padding = ' ';

	(void)p;
	if (flags->zero)
		padding = '0';
	input = va_arg(list, unsigned long int);
	converted = convert_unsigned_number(input, size);
	res = convert(converted, 16, 1);
	len = _len(res);
	if (flags->hash == 1 && input != 0)
		len += 2;
	if (!flags->minus)
		count += write_padding(width, len, padding);
	if (flags->hash == 1 && input != 0)
		count += putstr("0X");
	count += putstr(res);
	if (flags->minus && padding != '0')
		count += write_padding(width, len, padding);
	return (count);
}
