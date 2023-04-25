#include "main.h"

/**
 * print_b - function that convert and print from
 * int to binary.
 * @list: list of args.
 * @flags: pointer to flags.
 * @size: size of type
 * Return: number of char printed.
 */
int print_b(va_list list, fl_t *flags, int size)
{
	char *res;
	unsigned int input;
	int count;

	/* we will not use flags on custom specifier */
	(void)flags;
	(void)size;

	input = va_arg(list, unsigned int);
	res = convert(input, 2, 0);
	count = putstr(res);
	return (count);
}

/**
 * print_uint - function that print unsigned int
 * @list: list of args.
 * @flags: pointer to flags.
 * @size: the size of type
 * Return: number of char printed.
 */

int print_uint(va_list list, fl_t *flags, int size)
{
	unsigned long int input;
	char *res;
	int count;
	unsigned long int converted;

	/* we will not use flags*/
	(void)flags;

	input = va_arg(list, unsigned long int);
	converted = convert_unsigned_number(input, size);
	res = convert(converted, 10, 0);
	/*res = convert((unsigned int)input, 10, 0);*/
	count = putstr(res);
	return (count);
}

/**
 * print_octal - function that convert and print
 * from int to octal
 * @list: list of args.
 * @flags: pointer to flags.
 * @size: the size of type
 * Return: number of char printed.
 */

int print_octal(va_list list, fl_t *flags, int size)
{
	unsigned long int input;
	char *res;
	int count = 0;
	unsigned long int converted;

	input = va_arg(list, unsigned long int);
	converted = convert_unsigned_number(input, size);
	res = convert(converted, 8, 0);
	/*res = convert((unsigned int)input, 8, 0);*/
	if (flags->hash == 1 && input != 0)
		count = _putchar('0');
	count += putstr(res);
	return (count);
}

/**
 * print_hex_lower - function that convert and print
 * from int to hex in lowercase.
 * @list: list of args.
 * @flags: pointer to flags.
 * @size: the size of type.
 * Return: number of char printed,
 */

int print_hex_lower(va_list list, fl_t *flags, int size)
{
	unsigned long int input;
	char *res;
	int count = 0;
	unsigned long int converted;

	input = va_arg(list, unsigned long int);
	converted = convert_unsigned_number(input, size);
	res = convert(converted, 16, 0);
	/*res = convert((unsigned int)input, 16, 0);*/
	if (flags->hash == 1 && input != 0)
		count = putstr("0x");
	count += putstr(res);
	return (count);
}

/**
 * print_hex_upper - function that convert and print from
 * int to hex in uppercase.
 * @list: list of args
 * @flags: pointer to flags.
 * @size: The size of type.
 * Return: number of chars printed.
 */
int print_hex_upper(va_list list, fl_t *flags, int size)
{
	unsigned long int input;
	char *res;
	int count = 0;
	unsigned long int converted;

	input = va_arg(list, unsigned long int);
	converted = convert_unsigned_number(input, size);
	res = convert(converted, 16, 1);
	/*res = convert((unsigned int)input, 16, 1);*/
	if (flags->hash == 1 && input != 0)
		count = putstr("0X");
	count += putstr(res);
	return (count);
}
