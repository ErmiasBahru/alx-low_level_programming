#include <stdio.h>
/**
 * main - write a program that finds and prints the sum of
 * the even-valued terms, followed by a new line.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	long int a = 1, b = 2, sum = 0, res = 2;

	while (sum < 4000000)
	{
		sum = a + b;
		a = b;
		b = sum;
		if (sum % 2 == 0)
		{
			res += sum;
		}
	}
	printf("%li\n", res);
	return (0);
}
