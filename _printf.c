#include "main.h"

/**
 * process_format - Processes the format string
 * and calls appropriate print functions
 * @format: A string that is composed of zero or more directives
 * @args: va_list of arguments
 * @i: Pointer to the index of the current character in the format string
 * @r_val: Pointer to the total number of characters printed
 * Return: The number of characters printed
 */
void process_format(const char *format, va_list args, int *i, int *r_val)
{
	int (*p_func)(va_list, fl_t *);
	fl_t flags;

	while (*(format + *i))
	{
		if (format[*i] == '%' && format[*i + 1] == '\0')
			return;
		else if (*(format + *i) == '%')
		{
			init_flags(&flags);
			(*i)++;
			while (get_flags(*(format + *i), &flags) == 1)
				(*i)++;
			flags.zero_pad = 0;
			if (*(format + *i) == '0')
			{
				flags.zero_pad = 1;
				(*i)++;
			}
			p_func = get_print_func(*(format + *i));
			if (p_func != NULL)
				*r_val += p_func(args, &flags);
			else
			{
				if ((flags.space == 1 || flags.hash == 1 || flags.plus == 1) &&
				    *(format + *i) != '\0')
					*r_val += print_unkown_specifier(&flags, *(format + *i));
					/*r_val += _printf("%%%c",*(format + i));*/
			}
		}
		else
		{
			_putchar(*(format + *i));
			*r_val += 1;
		}
		(*i)++;
	}
}

/**
 * _printf - produces output according to a format
 * @format: A string that is composed of zero or more directives
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, r_val = 0;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	process_format(format, args, &i, &r_val);
	va_end(args);
	_putchar(-1);
	return (r_val);
}

