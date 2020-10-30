#include "holberton.h"

/**
 *print_number- A function that prints integer
 *@arg: The integer
 *Return: number of integer
 */

int print_number(va_list arg)
{
	int d = va_arg(arg, int);
	int number;
	int lastdigit = d % 10;
	int one_dig;
	int mult = 1;
	int i = 1;

	d = d / 10;
	number = d;

	if (lastdigit < 0)
	{
		_putchar('-');
		number = -number;
		d = -d;
		lastdigit = -lastdigit;
		i++;
	}
	if (number > 0)
	{
		while (number / 10 != 0)
		{
			mult = mult * 10;
			number = number / 10;
		}
		number = d;
		while (mult > 0)
		{
			one_dig = number / mult;
			_putchar(one_dig + '0');
			number = number % mult;
			mult = mult / 10;
			i++;
		}
	}
	_putchar(lastdigit + '0');

	return (i);
}
