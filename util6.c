#include "main.h"

/**
 * get_len_modifier - gets the length modifier
 * @format: character String
 * @p: pointer to the current index
 * Return: 1 (if length modifier is h)
 * 2 (if length modifier is l)
 * 0 otherwize
 */
int get_len_modifier(const char *format, int *p)
{
	int index = *p;
	int size = 0;
	
	if (format[index] == 'h')
		size = 1;
	else if (format[index] == 'l')
		size = 2;

	if (size != 0)
		*p = index + 1;
	else
		*p = index;
	return (size);
}

/**
 * convert_number - convert a number to a specific size
 * @n: the giving number
 * @size: the specific size
 * Return: the converted number
 */
long int convert_number(long int n, int size)
{
	if (size == 2)
		return (n);
	else if (size == 1)
		return ((short)n);
	return ((int)n);
}

/**
 * convert_unsigned_number - convert unsigned number to a specific size
 * @n: the giving unsigned number
 * @size: the giving size
 * Return: the converted number
 */
long int convert_unsigned_number(unsigned long int n, int size)
{
	if (size == 2)
		return (n);
	else if (size == 1)
		return ((unsigned short)n);
	return ((unsigned int)n);
}
