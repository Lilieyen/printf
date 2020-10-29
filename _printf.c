#include "holberton.h"
#include <stdarg.h>
#include <unistd.h>

/**
 *_strlen- Gets the length of a string
 *@s: string
 *
 *return:Length of a string
 */

int _strlen(char *s)
{

        int length = 0;

        while (*s)
        {
                s++;
                length++;
        }
        return (length);
}

/**
 *
 */
int _number(int d)
{
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
			number = number - (one_dig *mult);
			mult = mult / 10;
			i++;
		}
	}
	_putchar(lastdigit + '0');

	return (i);
}

/**
 *_printf- Prints anything to output
 *@format:Parameter 1
 *@...:Variable number of arguements
 *Return: Length
 */

int _printf(const char *format, ...)
{
        int i = 0;
        int length = 0;
        char char_arg;
        char *string_arg;
        va_list arguments;
        int j;
	int d;

        va_start(arguments, format);
        while (*(format + i))
        {
                if ((*(format + i)) != '%')
                {
                        if (write(1, format + i, 1) == -1)
                                return (-1);
                        length++;
                }
                else
                {
                        i += 1;
                        switch (*(format + i))
                        {
			case 'c':
				char_arg = va_arg(arguments, int);

				j = write(1, &char_arg, 1);
				if (j == -1)
					return (-1);
				length++;
				break;
			case 's':
				string_arg = va_arg(arguments, char *);

				j = write(1, string_arg, _strlen(string_arg));
				if (j == -1)
					return (-1);
				length += j;
				break;
			case '%':
				j = write(1, &("%"), 1);
				if (j == -1)
					return (-1);
				length++;
				break;
			case 'd':
                                d = va_arg(arguments, int);
                                length += _number(d);
				break;
			case 'i':
				d = va_arg(arguments, int);
                                length += _number(d);
				break;
                        }

                }
                i++;
        }
        return (length);
}
