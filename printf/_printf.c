#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
 * _printf - Function that produces output according to a format.
 * @format: Is a character string.
 * The format string is composed of zero or more directives.
 * Returns: the number of characters printed
 * (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	op_t opl[] = {
		{"c", op_c},
		{"s", op_s},
		{"%", op_percent},
		{"d", op_d},
		{"i", op_d},
		{"u", op_u},
		{"o", op_o},
		{"x", op_x},
		{"X", op_X},
		{"p", op_p},
		{"r", op_r}
	};
	va_list al;
	int x;
	int y;
	int length = 0;

	va_start(al, format);
	x = 0;
	while (format[x])
	{
		if (format[x] == '%')
		{
			y = 0;
			while (y < 11)
			{
				if (opl[y].op[0] == format[x + 1])
				{
					length += opl[y].func(al);
					x++;
				}
				y++;
			}
		}
		else
		{
			length += _putchar(format[x]);
		}
		x++;
	}
	va_end(al);
	return (length);
}
