#include "main.h"

/**
 * main - Entry point
 * Return: 0 (Success)
 */
int main(void)
{
	int i = 99;
	int *ptr;
	int r_val;

	ptr = &i;
	r_val = _printf("%p\n", ptr);
	printf("r_val : %d\n", r_val);

	r_val = printf("%p\n", ptr);
	printf("r_val : %d\n", r_val);
	return (0);
}
