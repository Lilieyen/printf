#include "holberton.h"
/**
 *print_char - prints a character
 *@arg: char to print
 *Return: 1 on success
 */

int print_char(va_list arg)
{
char c;

c = va_arg(arg, int);

_putchar(c);
return (1);
}
