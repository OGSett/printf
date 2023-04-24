#include "main.h"
/**
 * convert - converts an integer to a specific base
 * @n: the giving integer
 * @base: the base to be converted to
 * @upper_o_n: indicates if output upper od lower case
 * Return: the conversion string
 */
char *convert(unsigned long int n, int base, int upper_o_n)
{
	static char *base_digits;
	static char buffer[50];
	char *p_convert;

	base_digits = upper_o_n ? "0123456789ABCDEF" :
		"0123456789abcdef";

	p_convert = &buffer[49];
	*p_convert = '\0';

	do {
		*--p_convert = base_digits[n % base];
		n /= base;
	} while (n != 0);
	return (p_convert);
}
