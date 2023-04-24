#include "main.h"
/**
 * get_print_func - gets print function associated to a specifier
 * @sp: The giving specifier
 * @flags: pointer to flags
 * Return: The associated function
 */
int (*get_print_func(char sp))(va_list args, fl_t *flags)
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
		{'X', print_hex_upper},
		{'S', ex_print_all},
		{'p', print_address},
		{'r', print_rev},
		{'R', print_13}
	};

	int specifiers = 14, i = 0;

	while (i < specifiers)
	{
		if (sps[i].sp == sp)
			return (sps[i].func);
		i++;
	}
	return (NULL);
}
