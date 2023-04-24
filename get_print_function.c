#include "main.h"
/**
 * get_print_func - gets print function associated to a specifier
 * @sp: The giving specifier
 * Return: The associated function
 */
int (*get_print_func(char sp))(va_list args)
{

	sp_t sps[] = {
		{'c', print_c},
		{'s', print_s},
		{'%', print_percent},
		{'i', print_n},
		{'d', print_n},
		{'b', print_b},
		{'u', print_uint},
		{'o', print_octal},
		{'x', print_hex_lower},
		{'X', print_hex_upper}
	};

	int specifiers = 10, i = 0;

	while (i < specifiers)
	{
		if (sps[i].sp == sp)
			return (sps[i].func);
		i++;
	}
	return (NULL);
}
