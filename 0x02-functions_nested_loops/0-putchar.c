#include "main.h"
/**
 * main - entry block
 * @void: no argument
 * Return: 0
 **/
int main(void)
{
	char alx[] = "_putchar";

	int c;

	for (c = 0; c < 9; c++)
	{
		_putchar(alx[c]);
	}
	_putchar('\n');
	return (0);
}
