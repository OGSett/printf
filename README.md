Team project : _printf

# NAME
_printf - produces output according to a format

# SYNOPSIS
**_printf** FORMAT [ARGUMENT]...

# DESCRIPTION
**_printf** Print ARGUMENT(s) according to FORMAT

## conversion specifier
A character that specifies the type of conversion to be applied.

| conversion specifier | meaning                |
| -------------------- | ---------------------- |
| d, i | The int argument is converted to signed decimal notation |
| c | The int argument is converted to an unsigned char |
| s | the const char * argument is expected to be a pointer to an array of character type (pointer to a string). Characters from the array are written up to (but not including) a terminating null byte ('\0') |
| o | The unsigned int argument is converted to unsigned octal |
| u | The unsigned int argument is converted to unsigned decimal |
| x | The unsigned int argument is converted to unsigned hexadecimal by using the lowercase for lettres 'abcdef' |
| X | The unsigned int argument is converted to unsigned hexadecimal by using the uppercase for lettres 'ABCDEF' |
| S | This is a custom specifier that prints a String and replace a Non printable character (0 < ASCII value < 32 or >= 127) by \x followed by the ASCII code value in hexadecimal (upper case - always 2 characters) |
| p | The void * pointer argument is printed in hexadecimal.
| r | This is a custom specifier that prints the reversed string |
| R | This is a custom specifier that prints the rot13'ed string |

## Flags
The character % is followed by zero or more of the following flags:

| flag | meaning			|
| ---- | ------------------------------ |
| + | A sign (+ or -) should always be placed before a number produced by a signed conversion.  By default, a sign is used only for negative numbers.  A  + overrides a space if both are used. |
| ' ' | (a space) A blank should be left before a positive number (or empty string) produced by a signed conversion. |
| # | The  value should be converted to an "alternate form":<br/>- For o conversions, the first character of the output string is made zero (by prefixing a 0 if it was not zero already).<br/>- For x and X conversions, a nonzero result has the string "0x" (or "0X" for X conversions) prepended to it. |


## Length modifier
Here "integer conversion" stands for d, i, o, u, x, or X conversion:

| modifier | meaning |
| -------- | ------- |
| h | A following integer conversion corresponds to a short int or unsigned short int argument |
| l | A following integer conversion corresponds to a long int or unsigned long int argument |

## Field width
An optional decimal digit string (with nonzero first digit) specifying a minimum field width.
If the converted value has fewer characters  than  the  field width,  it  will  be padded with spaces on the left.
Instead of a decimal digit string one may write "*" to specify that the field width is given in the next argument.
In no case does a nonexistent or small field width cause truncation of a field; if the result of a conversion is wider than the field width, the field is expanded to contain the conversion result.

# Copyright
Authors: Yussef EL MEKKAOUI & HAJAR EL ABDELLAOUI
