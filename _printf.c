#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: A string that is composed of zero or more directives
 * Return: The number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int (*p_func)(va_list, fl_t *);
	int i = 0, r_val = 0;
	fl_t flags;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (*(format + i))
	{
		if (format[i] == '%' && format[i + 1] == '\0')
			return (-1);
		else if (*(format + i) == '%')
		{
			init_flags(&flags);
			i++;
			while (get_flags(*(format + i), &flags) == 1)
				i++;
			p_func = get_print_func(*(format + i));
			if (p_func != NULL)
				r_val += p_func(args, &flags);
			else
			{
				if ((flags.space == 1 || flags.hash == 1 || flags.plus == 1) &&
						*(format + i) != '\0')
					r_val += print_unkown_specifier(&flags, *(format + i));
					/*r_val += _printf("%%%c",*(format + i));*/
			}
		}
		else
		{
			_putchar(*(format + i));
			r_val += 1;
		}
		i++;
	}
	va_end(args);
	_putchar('\0');
	return (r_val);
}
