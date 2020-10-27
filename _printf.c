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

                        }

                }
                i++;
        }
        return (length);
}
