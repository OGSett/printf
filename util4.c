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
 * @flags: pointer to flags.
 * @width: the width of the field.
 * @size: the size of type.
 * Return: number of char printed
 */
int print_rev(va_list list, fl_t *flags, int width, int size)
{
	char *input;
	int count = 0;
	int len;

	/* we will not use flags with custom specifier */
	(void)flags;
	(void)size;
	(void)width;

	input = va_arg(list, char *);
	if (input == NULL)
		return (putstr("[%r]\n"));
	len = _len(input) - 1;
	while (len >= 0)
	{
		count += _putchar(input[len]);
		len--;
	}
	return (count);
}

/**
 * print_13 - function that extract the input string from the "va_list"
 * and print it in a rot13'ed way.
 * @list: list of args.
 * @flags: pointer to flags.
 * @width: the width of the field.
 * @size: the size of type
 * Return: the number of char printed.
 */

int print_13(va_list list, fl_t *flags, int width, int size)
{
	int i;
	int count = 0;
	char temp;
	char *input;

	/* we will not use flags with custom specifier */
	(void)flags;
	(void)size;

	input = va_arg(list, char *);
	if (input == NULL)
		return (0);
	i = 0;
	while (input[i] != '\0')
	{
		temp = input[i];
		if ((temp >= 'A' && temp <= 'M')
				|| (temp >= 'a' && temp <= 'm'))
			temp += 13;
		else if ((temp >= 'N' && temp <= 'Z')
				|| (temp >= 'n' && temp <= 'z'))
			temp -= 13;
		count += _putchar(temp);
		i++;
	}
	return (count);
}
