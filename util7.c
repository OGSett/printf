#include "main.h"
/**
 * get_precision - gets the field precision
 * @format: a character string
 * @p: a pointer to the current index of format
 * @list: list of arguments
 * @f: a pointer to flags.
 * Return: the precision
 */
int get_precision(const char *format, int *p, va_list list, fl_t *f)
{
	int index = *p;
	int precision = 0;

	if (format[index])
	{
		if (format[index] == '.')
		{
			index++;
			while (format[index])
			{
				if (format[index] == '*')
				{
					index++;
					precision = va_arg(list, int);
					f->precision = 1;
					break;
				}
				else if (_is_digit(format[index]))
				{
					precision *= 10;
					precision += format[index] - '0';
				}
				else
				{
					f->precision = 1;
					break;
				}
				index++;
			}
		}
	}
	*p = index;
	return (precision);
}

/**
 * substr - extracts a part of a string
 * @str: the giving string
 * @n: the number of bytes
 * Return: the substring
 */
char *substr(char *str, unsigned int n)
{
	char *sub;
	unsigned int i = 0;

	sub = malloc(n * sizeof(char));
	if (!sub)
		return (NULL);
	while (i < n)
	{
		sub[i] = str[i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

/**
 * add_precision - add the padding '0' to get the precision
 * @num: the number digits stored in a string
 * @len: number of digits of the number
 * @precision: the field precision
 * Return: the new string with the precision or NULL if fails
 */
char *add_precision(char *num, int len, int precision)
{
	char *new;
	int i = 0, j = 0;

	new = malloc(precision * sizeof(char));
	if (!new)
		return (NULL);
	while (i < (precision - len))
	{
		new[i] = '0';
		i++;
	}
	while (num[j])
	{
		new[i] = num[j];
		i++, j++;
	}
	new[i] = '\0';
	return (new);
}
/**
 * print_num_precision - add the padding '0' to get the precision
 * @n: the number of 0 to print
 */
void print_num_precision(int n)
{
	while (n--)
		_putchar('0');
}
