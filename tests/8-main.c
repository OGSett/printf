#include "main.h"
#include <limits.h>
/**
 * main - tests flags
 * Return: 0 (Success)
 */
int main(void)
{
	unsigned int ui;
	int r_val = 0;

	ui = (unsigned int)INT_MAX + 1024;
	printf("----------------- plus flag ------------------\n");
	r_val = printf("integer: [%+d]\n", INT_MAX);
	printf("r_val = %d\n", r_val);
	r_val = printf("To octal: [%+o]\n", ui);
	printf("r_val = %d\n", r_val);
	r_val = printf("To hexa lower: [%+x]\n", ui);
	printf("r_val = %d\n", r_val);
	r_val = printf("To hexa upper: [%+X]\n", ui);
	printf("r_val = %d\n", r_val);
	r_val = printf("To unsigned int: [%+u]\n", ui);
	printf("r_val = %d\n", r_val);

	printf("----------------- plus space ------------------\n");
        r_val = printf("integer: [% d]\n", INT_MAX);
        printf("r_val = %d\n", r_val);
        r_val = printf("To octal: [% o]\n", ui);
        printf("r_val = %d\n", r_val);
        r_val = printf("To hexa lower: [% x]\n", ui);
        printf("r_val = %d\n", r_val);
        r_val = printf("To hexa upper: [% X]\n", ui);
        printf("r_val = %d\n", r_val);
        r_val = printf("To unsigned int: [% u]\n", ui);
        printf("r_val = %d\n", r_val);

	printf("----------------- plus hash ------------------\n");
        r_val = printf("integer: [%#d]\n", INT_MAX);
        printf("r_val = %d\n", r_val);
        r_val = printf("To octal: [%#o]\n", ui);
        printf("r_val = %d\n", r_val);
        r_val = printf("To hexa lower: [%#x]\n", ui);
        printf("r_val = %d\n", r_val);
        r_val = printf("To hexa upper: [%#X]\n", ui);
        printf("r_val = %d\n", r_val);
        r_val = printf("To unsigned int: [%#u]\n", ui);
        printf("r_val = %d\n", r_val);

	printf("---------------------- _printf output ----------------\n");
	printf("----------------- plus flag ------------------\n");
        r_val = _printf("integer: [%+d]\n", INT_MAX);
        printf("r_val = %d\n", r_val);
        r_val = _printf("To octal: [%+o]\n", ui);
        printf("r_val = %d\n", r_val);
        r_val = _printf("To hexa lower: [%+x]\n", ui);
        printf("r_val = %d\n", r_val);
        r_val = _printf("To hexa upper: [%+X]\n", ui);
        printf("r_val = %d\n", r_val);
        r_val = _printf("To unsigned int: [%+u]\n", ui);
        printf("r_val = %d\n", r_val);

        printf("----------------- plus space ------------------\n");
        r_val = _printf("integer: [% d]\n", INT_MAX);
        printf("r_val = %d\n", r_val);
        r_val = _printf("To octal: [% o]\n", ui);
        printf("r_val = %d\n", r_val);
        r_val = _printf("To hexa lower: [% x]\n", ui);
        printf("r_val = %d\n", r_val);
        r_val = _printf("To hexa upper: [% X]\n", ui);
        printf("r_val = %d\n", r_val);
        r_val = _printf("To unsigned int: [% u]\n", ui);
        printf("r_val = %d\n", r_val);

        printf("----------------- plus hash ------------------\n");
        r_val = _printf("integer: [%#d]\n", INT_MAX);
        printf("r_val = %d\n", r_val);
        r_val = _printf("To octal: [%#o]\n", ui);
        printf("r_val = %d\n", r_val);
        r_val = _printf("To hexa lower: [%#x]\n", ui);
        printf("r_val = %d\n", r_val);
        r_val = _printf("To hexa upper: [%#X]\n", ui);
        printf("r_val = %d\n", r_val);
        r_val = _printf("To unsigned int: [%#u]\n", ui);
        printf("r_val = %d\n", r_val);


	return (0);
}
