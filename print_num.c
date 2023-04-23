#include "main.h"

/**
 * count_digit - counts nbr of digits
 * @n: the giving number
 * Return: nbr of digits
 */
int count_digit(unsigned int n)
{
	int count = 0;

	do {
		count++;
		n /= 10;
	} while (n != 0);
	return (count);
}


/**
 * putnbr - function that print numbers
 * @nbr: number to be printed
 * Return: digit printed
 */

void putnbr(unsigned int nbr)
{
	if (nbr >= 10)
	{
		putnbr(nbr / 10);
		putnbr(nbr % 10);
	}
	else
	{
		_putchar(nbr + '0');
	}
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
	i += count_digit(num);
	putnbr(num);
	return (i);
}
