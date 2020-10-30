#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int int_len(int number);
int handle_switch(char format, va_list arguments);
int print_char(va_list arg);
int print_number(va_list arg);
int _printf(const char *format, ...);
int _putchar(char c);

#endif
