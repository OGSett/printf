#include "main.h"

/**
 * main - test %s %c %
 * Return: 0 always
 */
int main(void)
{
	char c = 'a';
	char *str = "Hello world !!";
	int r_val;
	char *s = NULL;

	printf("------------- printf output ----------------\n");
	r_val = printf("%s %c 100%%\n", str, c);
	printf("r_val = %d\n", r_val);

	printf("------------- _printf output ----------------\n");
        r_val = _printf("%s%c100%%\n", "abcd", 'e');
        printf("r_val = %d\n", r_val);

	r_val = printf(NULL);
	printf("r_val = %d\n", r_val);

	r_val = _printf(NULL);
        printf("r_val = %d\n", r_val);
	return (0);
}
