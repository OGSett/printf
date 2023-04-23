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
		{'d', print_n}
	};

	int specifiers = 5, i = 0;

	while (i < specifiers)
	{
		if (sps[i].sp == sp)
			return (sps[i].func);
		i++;
	}
	return (NULL);
}
