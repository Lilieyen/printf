#include "holberton.h"
#include <stdarg.h>
#include <unistd.h>

/**
 *_printf- Prints anything to output
 *@format:Parameter 1
 *@...:Variable number of arguements
 *Return: length
 */

int _printf(const char *format, ...)
{
	int length = 0, i = 0;
	int check_flag = 0;
	char flags[] = "csdi%";
	va_list arguments;

	va_start(arguments, format);
	if (format == NULL)
	{
		return (-1);
	}

	while (*format)
	{
		if (*format != '%')
		{
			int j = write(1, format, 1);

			if (j == -1)
			{
				return (-1);
			}
			length++;
		}
		else
		{
			format++;
			if (!*format)
			{
				return (-1);
			}

			while (flags[i])
			{
				if (*format == flags[i])
				{
					check_flag = 1;
				}
				i++;
			}
			if (check_flag == 1)
			{
				length += handle_switch(*format, arguments);
			}
		}

		format++;
	}
	return (length);
}
