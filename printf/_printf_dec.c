#include "main.h"
/**
 * pd - Print decimals
 * @arg: arguments
 * Return: Number of elements of the decimal argument
 **/

int pd(va_list arg)
{
	int n, num, ld;
	int dig;
	int exp, con;
	int val = 1;

	n = va_arg(arg, int);
	if (n < 0)
		val = -1;
	ld = n % 10;
	con = 1;
	exp = 1;
	n = n / 10;
	num = n;
	if (val < 0)
	{
		_putchar('-');
		num = -num;
		n = -n;
		ld = -ld;
		con++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}
		num = n;
		while (exp > 0)
		{
			dig = num / exp;
			_putchar(dig  + '0');
			num = num - (dig * exp);
			exp = exp / 10;
			con++;
		}
	}
	_putchar(ld + '0');
	return (con);
}
