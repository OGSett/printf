#include "main.h"

/**
 * count_digit - counts nbr of digits
 * @n: the giving number
 * Return: nbr of digits
 */
int count_digit(unsigned long int n)
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

void putnbr(unsigned long int nbr)
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
 * @flags: pointer to flags.
 * @width: the width of the field.
 * @size: the size of type.
 * Return: number of digit printed
 */

int print_n(va_list list, fl_t *flags, int width, int size)
{
	long int n;
	int i = 0;
	int k, d;
	int count = 0;
	int plus = 0, mines = 0, space = 0;
	unsigned long int num;

	n = va_arg(list, long int);
	n = convert_number(n, size);
	if (n < 0)
	{
		mines = 1, i++;
		num = (unsigned long int)-n;
	}
	else
	{
		if (flags->plus == 1)
			plus = 1, i++;
		else if (flags->space == 1)
			space = 1, i++;
		num = n;
	}
	i += count_digit(num);
	if (width > i && !flags->zero)
	{
		d = width - i;
		for (k = 0; k < d; k++)
			count += _putchar(' ');
	}
	if (mines == 1)
		_putchar('-');
	if (space == 1)
		_putchar(' ');
	if (plus == 1)
		_putchar('+');
	putnbr(num);
	i += count;
	return (i);
}
