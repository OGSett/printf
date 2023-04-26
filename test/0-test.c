#include "main.h"

int main(void)
{
	int i = 55;
	int *p = &i;

	_printf("%8c\n", 'h');
	_printf("%8s\n", "Hello world!!!");
	_printf("%8d\n", 857429);
	_printf("%8i\n", 857429);
	_printf("%8u\n", 84572);
	_printf("%8x\n", 89);
	_printf("%8o\n", 89);
	_printf("%8x\n", 89);
	_printf("%8X\n", 89);
	_printf("%20p\n", p);
	_printf("[%c]\n", '\0');
	return (0);
}
