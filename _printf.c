#include "main.h"
/**
 * _printf - produces output according to a format
 * @format: A string that is composed of zero or more directives
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int (*p_func)(va_list);
	int i = 0, r_val = 0;

	va_start(args, format);
	while (*(format + i))
	{
		if (*(format + i) == '%' && format[i + 1] != '\0')
		{
			i++;
			p_func = get_print_func(*(format + i));
			if (p_func != NULL)
				r_val += p_func(args);
		}
		else if (format[i] == '%' && format[i + 1] == '\0')
		{
			return (-1);
		}
		else
		{
			_putchar(*(format + i));
			r_val += 1;
		}
		i++;
	}
	va_end(args);
	return (r_val);
}
