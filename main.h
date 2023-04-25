#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#define SIZE_BUFFER 1024

/**
 * struct flags - struct of flags characters
 * @plus: The + flag
 * @space: The space flag
 * @hash: The # flag
 * @zero_pad: the 0 flag.
 */
typedef struct flags
{
        int plus;
        int space;
        int hash;
	int zero_pad;
} fl_t;


/**
 * struct specifier - struct specifier
 * @sp: The specifier
 * @func: The associated function
 */
typedef struct specifier
{
	char sp;
	int (*func)(va_list, fl_t *);
} sp_t;


int _printf(const char *format, ...);
int _putchar(char c);
int (*get_print_func(char sp))(va_list args, fl_t *flags);
int     _putchar(char c);
int print_c(va_list list, fl_t *flags);
int putstr(char *str);
int print_s(va_list list, fl_t *flags);
int print_percent(va_list list, fl_t *flags);
void putnbr(unsigned int nbr);
int print_n(va_list list, fl_t *flags);
int count_digit(unsigned int n);
int print_octal(va_list list, fl_t *flags);
int print_uint(va_list list, fl_t *flags);
int print_b(va_list list, fl_t *flags);
int print_hex_lower(va_list list, fl_t *flags);
int print_hex_upper(va_list list, fl_t *flags);
char *convert(unsigned long int n, int base, int upper_o_n);
int ex_print_all(va_list list, fl_t *flags);
int print_all(char *str);
int print_address(va_list list, fl_t *flags);
int print_rev(va_list list, fl_t *flags);
int _len(char *str);
int print_13(va_list list, fl_t *flags);
int get_flags(char c, fl_t *f);
int get_print_flags(fl_t *flags);
int print_unkown_specifier(fl_t *flags, char c);
void init_flags(fl_t *flags);
#endif
