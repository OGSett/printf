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

#endif
