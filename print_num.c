#include "main.h"

/**
 * putnbr - function that print numbers
 * @nbr: number to be printed
 * Return: digit printed
 */

int putnbr(int nbr)
{
	static int i;

	if (nbr < 0)
	{
		_putchar('-');
		nbr = -nbr;
		i++;
	}
	if (nbr >= 10)
	{
		putnbr(nbr / 10);
		putnbr(nbr % 10);
	}
	else
	{
		_putchar(nbr + '0');
		i++;
	}
	return (i);
}

/**
 * print_n - the function tha call putnbr.
 * @list: list of args
 * Return: number of digit printed
 */

int print_n(va_list list)
{
	int n;
	int i;

	n = va_arg(list, int);
	i = putnbr(n);
	return (i);
}
