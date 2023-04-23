#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

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
int putnbr(int nbr);
int print_n(va_list list);
#endif
