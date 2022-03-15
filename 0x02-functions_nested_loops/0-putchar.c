#include "main.h"
/**
 * main - entry block
 * @void: no argument
 * Return: 0
 **/
int main(void)
{
	char ermias[] = "Ermias";

	int c;

	for (c = 0; c < 9; c++)
	{
		_putchar(ermias[c]);
	}
	_putchar('\n');
	return (0);
}
