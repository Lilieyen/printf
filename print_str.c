#include "holberton.h"

/**
 *print_str- A function that prints a string
 *@arg:The string
 *Return: number of strings
 */
int print_str(va_list arg)
{
char *s;

int i = 0;

s = va_arg(arg, char *);
if (s == NULL)
{
s = "(null)";
}
while (s[i] != '\0')
{
_putchar(s[i]);
i++;
}
return (i);
}
