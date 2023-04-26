#include "main.h"


int main() {
    int num1 = 42;
    int num2 = -1234;
    float floatNum = 3.14159;
    char str[] = "Hello, world!";
    
    /* Testing width field with integers*/
    printf("Testing width field with integers:\n");
    _printf("|%5d|\n", num1);  /* Output: |   42| */
    _printf("|%-5d|\n", num1); /* Output: |42   | */
    _printf("|%5d|\n", num2);  /* Output: |-1234| */
    
    /* Testing width field with floating-point numbers */
    printf("\nTesting width field with floating-point numbers:\n");
    _printf("|%7.2f|\n", floatNum);   /* Output: |   3.14| */
    _printf("|%-7.2f|\n", floatNum);  /* Output: |3.14   | */
    
    /* Testing width field with strings*/
    printf("\nTesting width field with strings:\n");
    _printf("|%10s|\n", str);   /* Output: |Hello, world!| */
    _printf("|%-10s|\n", str);  /* Output: |Hello, world!| */

    return 0;
}

