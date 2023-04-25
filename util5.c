#include "main.h"

/**
 * get_flags - function that checks the existing of flags
 * @c: the giving character
 * @f: a pointer to an element of struct flags
 *
 * Return: 1 if a flag exist, 0 otherwize
 */
int get_flags(char c, fl_t *f)
{
	int exist_flag = 0;

	switch (c)
	{
		case '+':
			f->plus = 1;
			exist_flag = 1;
			break;
		case ' ':
			f->space = 1;
			exist_flag = 1;
			break;
		case '#':
			f->hash = 1;
			exist_flag = 1;
			break;
		case '0':
			f->zero_pad = 1;
			exist_flag = 1;
			break;
	}
	return (exist_flag);
}
/**
 * get_print_flags - returns the string of flags to be printed
 * @flags: pointer to flags
 * Return: flags str
 */
int get_print_flags(fl_t *flags)
{
	int count = 0;

	if (flags->hash == 1)
		count += _putchar('#');
	if (flags->plus == 1)
		count += _putchar('+');
	else if (flags->space == 1)
		count += _putchar(' ');
	else if (flags->zero_pad == 1)
		count += _putchar('0');
	return (count);
}
/**
 * print_unkown_specifier - prints unkown specifier
 * @flags: pointer to flags
 * @c: unkown specifier
 * Return: nbr of printed characters
 */
int print_unkown_specifier(fl_t *flags, char c)
{
	int count = 0;

	count += _putchar('%');
	count += get_print_flags(flags);
	count += _putchar(c);
	return (count);
}

/**
 * init_flags - initialize flags
 * @flags: pointer to flags
 */
void init_flags(fl_t *flags)
{
	flags->hash = 0;
	flags->space = 0;
	flags->plus = 0;
	flags->zero_pad = 0;
}
