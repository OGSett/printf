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

/**
 * _is_digit - checks if a character is digit
 * @c: the giving character
 * Return: 1 (if c is digit), 0 otherwize
 */
int _is_digit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

/**
 * get_field_width - gets the field width
 * @format: a character string
 * @p: a pointer to the current index of format
 * @list: list of arguments
 * Return: the width
 */
int get_field_width(const char *format, int *p, va_list list)
{
	int index = *p;
	int width = 0;

	while (*(format + index))
	{
		if (_is_digit(*(format + index)))
		{
			width *= 10;
			width += *(format + index) - '0';
		}
		else if (*(format + index) == '*')
		{
			index++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
		index++;
	}
	*p = index;
	return (width);
}

