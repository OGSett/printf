#include "main.h"

/**
 * putnbr - function that print numbers
 * @nbr: number to be printed
 * Return: digit printed
 */

int putnbr(unsigned int nbr)
{
	static int z;

	if (nbr >= 10)
	{
		putnbr(nbr / 10);
		putnbr(nbr % 10);
	}
	else
	{
		_putchar(nbr + '0');
		z++;
	}
	return (z);
}

/**
 * print_n - the function tha call putnbr.
 * @list: list of args
 * Return: number of digit printed
 */

int print_n(va_list list)
{
	int n;
	int i = 0;
	unsigned int num;

	n = va_arg(list, int);
	if (n < 0)
	{
		_putchar('-');
		i++;
		num = -n;
	}
	else
		num = n;

	i += putnbr(num);
	return (i);
}
