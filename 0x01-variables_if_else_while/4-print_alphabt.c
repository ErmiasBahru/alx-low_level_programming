#include <stdio.h>

/**
* main - Print the alphabet in lowercase letters, except for e and q
*
* Return: Always 0 (Success)
*/
int main(void)
{
		char aphabet;

		for (aphabet = 'a'; aphabet <= 'z'; aphabet++)
		{
		if (aphabet != 'e' && aphabet != 'q')
		putchar(aphabet);
		}
		putchar('\n');

	return (0);
}
