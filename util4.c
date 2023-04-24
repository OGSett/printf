#include "main.h"

/**
 * _len - function that calculate lenght of a string
 * @str: string to be calculated
 * Return: lenght
 */

int _len(char *str)
{
	int len = 0;

	while (str[len])
		len++;
	return (len);
}

/**
 * print_rev - function that print and reverse a string
 * @list: list of args
 * Return: number of char printed
 */

int print_rev(va_list list)
{
	char *input;
	int count = 0;
	int len;

	input = va_arg(list, char *);
	if (input == NULL)
		input = "(null)";
	len = _len(input);
	while (len-- >= 0)
	{
		count += _putchar(input[len]);
	}
	return (count);
}
