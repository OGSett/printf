#include "main.h"
/**
 * get_precision - gets the field precision
 * @format: a character string
 * @p: a pointer to the current index of format
 * @list: list of arguments
 * Return: the precision
 */
int get_precision(const char *format, int *p, va_list list)
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
					break;
				}
				else if (_is_digit(format[index]))
				{
					precision *= 10;
					precision += format[index] - '0';
				}
				else
					break;
				index++;
			}
		}
	}
	*p = index;
	return (precision);
}
