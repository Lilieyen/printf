#include "holberton.h"
#include <unistd.h>
/**
 *handle_switch - selects format specifier
 *@format: format specifier
 *@arguments: unknown variadic arguments
 *Return: length of printed elements
 */

int handle_switch(char format, va_list arguments)
{
int length = 0;

switch (format)
{
case 'c':
length += print_char(arguments);
break;
case 's':
length += print_str(arguments);
break;
case '%':
write(1, &("%"), 1);
length++;
break;
case 'd':
length += print_number(arguments);
break;
case 'i':
length += print_number(arguments);
break;
}
return (length);
}
