#include "main.h"

/*
 * @BUFFER[SIZE_BUFFER]: the buffer where the printed char are stored
 */

static char BUFFER[SIZE_BUFFER];

/*
 * @k: counter of char printed.
 */

static int k = 0;

/**
 * _putchar - function that write char.
 * @c: char to be printed
 * Description: Use a local buffer of 1024 chars in order
 * to call write as little as possible.
 * Return: 1 if printed, -1 otherwise.
 */

int	_putchar(char c)
{

	if ((c == -1 && k > 0) || k == SIZE_BUFFER)
	{
		write(1, &BUFFER[0], k);
		k = 0;
	}
	else if (c != -1)
	{
		BUFFER[k] = c;
		k++;
	}
	return (1);
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
