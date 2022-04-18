#include "main.h"
/**
 * pc - Prints character c
 * @arg: character to print
 * Return: number of characters printed
 **/
int pc(va_list arg)
{
	char c;

	c = va_arg(arg, int);
	_putchar(c);
	return (1);
}
