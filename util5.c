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
		case '+': f->plus = 1;
			  exist_flag = 1;
			  break;
		case ' ': f->space = 1;
			  exist_flag = 1;
			  break;
		case '#': f->hash = 1;
			  exist_flag = 1;
	}
	return (exist_flag);
}
