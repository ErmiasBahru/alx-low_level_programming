#include "main.h"

/**
 * ps - Print array of characters
 * @arg: arguments
 * Return: Number of the length of every element of the array
 **/

int ps(va_list arg)
{
	int con = 0;
	char *str;

	str = va_arg(arg, char *);
	if (str == NULL)
		str = "(null)";

	while (str[con] != '\0')
	{
		_putchar(str[con]);
		con++;
	}
	return (con);
}
