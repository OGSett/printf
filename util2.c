#include "main.h"

/**
 * print_b - function that convert and print from
 * int to binary.
 * @list: list of args
 * Return: number of char printed.
 */

int print_b(va_list list)
{
	char *res;
	unsigned int input;
	int count;

	input = va_arg(list, unsigned int);
	res = convert(input, 2, 0);
	count = putstr(res);
	return (count);
}

/**
 * print_uint - function that print unsigned int
 * @list: list of args.
 * Return: number of char printed.
 */

int print_uint(va_list list)
{
	unsigned int input;
	char *res;
	int count;

	input = va_arg(list, unsigned int);
	res = convert(input, 10, 0);
	count = putstr(res);
	return (count);
}

/**
 * print_octal - function that convert and print
 * from int to octal
 * @list: list of args.
 * Return: number of char printed.
 */

int print_octal(va_list list)
{
	unsigned int input;
	char *res;
	int count;

	input = va_arg(list, unsigned int);
	res = convert(input, 8, 0);
	count = putstr(res);
	return (count);
}

/**
 * print_hex_lower - function that convert and print
 * from int to hex in lowercase.
 * @list: list of args.
 * Return: number of char printed,
 */

int print_hex_lower(va_list list)
{
	unsigned int input;
	char *res;
	int count;

	input = va_arg(list, unsigned int);
	res = convert(input, 16, 0);
	count = putstr(res);
	return (count);
}

/**
 * print_hex_upper - function that convert and print from
 * int to hex in uppercase.
 * @list: list of args
 * Return: number of chars printed.
 */
int print_hex_upper(va_list list)
{
	unsigned int input;
	char *res;
	int count;

	input = va_arg(list, unsigned int);
	res = convert(input, 16, 1);
	count = putstr(res);
	return (count);
}
