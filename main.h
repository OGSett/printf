#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#define SIZE_BUFFER 1024

/**
 * struct specifier - struct specifier
 * @sp: The specifier
 * @func: The associated function
 */
typedef struct specifier
{
	char sp;
	int (*func)(va_list);
} sp_t;

int _printf(const char *format, ...);
int _putchar(char c);
int (*get_print_func(char sp))(va_list args);
int     _putchar(char c);
int print_c(va_list list);
int putstr(char *str);
int print_s(va_list list);
int print_percent(va_list list);
void putnbr(unsigned int nbr);
int print_n(va_list list);
int count_digit(unsigned int n);
int print_octal(va_list list);
int print_uint(va_list list);
int print_b(va_list list);
int print_hex_lower(va_list list);
int print_hex_upper(va_list list);
char *convert(unsigned int n, int base, int upper_o_n);
#endif
