#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
 * _printf - function printf selector
 * @format: format
 * Return: Number of printed characters excluding the null
 **/
int _printf(const char *format, ...)
{
	int con1 = 0, con2 = 0, flag, lon = 0;
	va_list arg;

	cf_t print[] = { {"c", pc}, {"s", ps}, {"d", pd}, {"i", pi}, {NULL, NULL} };

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(arg, format);
	while (format[con1] != '\0')
	{
		if (format[con1] == '%' && format[con1 + 1] != '%')
		{
			con2 = 0;
			flag = 0;
			while (print[con2].p != NULL)
			{
				if (format[con1 + 1] == print[con2].print[0])
				{
					lon = lon + print[con2].p(arg);
					flag = 1;
					con1++; }
				con2++;
			}
			if (flag == 0)
			{
				_putchar (format[con1]);
				lon = lon + 1; }
		}
		else if (format[con1] == '%' && format[con1 + 1] == '%')
		{
			_putchar ('%');
			con1++;
			lon = lon + 1; }
		else
		{
			_putchar (format[con1]);
			lon = lon + 1; }
		con1++;	}
	va_end(arg);
	return (lon);
}
