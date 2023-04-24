#include "main.h"
#include <stdio.h>
#include <limits.h>
/**
 * main - tests %u %o %x and %X
 * Return: 0 (Success)
 */
int main(void)
{
	unsigned int ui;
	int r_val = 0;
	char buffer[SIZE_BUFFER] = "";

	ui = (unsigned int)INT_MAX + 1024;

	printf("------------------- printf output-----------------\n");
	r_val = printf("Unsigned:[%u]\n", ui);
	printf("r_val : %d\n", r_val);
	r_val = printf("Unsigned octal:[%o]\n", ui);
	printf("r_val : %d\n", r_val);
	r_val = printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	printf("r_val : %d\n", r_val);

	printf("------------------- _printf output-----------------\n");
	r_val = _printf("Unsigned:[%u]\n", ui);
        printf("r_val : %d\n", r_val);
        r_val = _printf("Unsigned octal:[%o]\n", ui);
        printf("r_val : %d\n", r_val);
        r_val = _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
        printf("r_val : %d\n", r_val);
	r_val = _printf("binary of %d is : %b \n", 'a', 'a');
	/*while (i < 1100)
	{
		buffer[i] = a;
		i++;
	}
	buffer[i] = '\0';8*/
	r_val = _printf("%s \n", buffer);
	printf("r_val : %d\n", r_val);
	_printf("%S\n", "Best\nSchool");

	return (0);
}
