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
 * @precision: the field precision.
 * Return: number of digit printed
 */

int print_n(va_list list, fl_t *flags, int width, int size, int precision)
{
	long int n;
	int plus = 0, mines = 0, space = 0, count = 0, i = 0;
	unsigned long int num;
	char padding = ' ', sign;

	(void)precision;
	if (flags->zero)
		padding = '0';

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
	sign = get_sign(mines, space, plus);
	if ((mines || space || plus) && flags->zero)
		_putchar(sign);
	if (!flags->minus)
		count += write_padding(width, i, padding);
	if ((mines || space || plus) && !flags->zero)
		_putchar(sign);
	putnbr(num);
	if (flags->minus && padding != '0')
		count += write_padding(width, i, padding);
	i += count;
	return (i);
}

/**
 * get_sign - gets the sign
 * @mines: minus sign
 * @space: space flag
 * @plus: plus flag
 * Return: return the sign
 */
char get_sign(int mines, int space, int plus)
{
	char sign;

	if (mines)
		sign = '-';
	if (space)
		sign = ' ';
	if (plus)
		sign = '+';
	return (sign);
}
