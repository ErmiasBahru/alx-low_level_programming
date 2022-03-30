#include "main.h"
/**
 * is_prime_num - helper function
 * @n: num
 * @x: num
 * Return: output
 */
int is_prime_num(int n, int x)
{
	if (n <= 1 || (n != x && n % x == 0))
	{
		return (0);
	}
	else if (n == x)
	{
		return (1);
	}
	return (is_prime_num(n, x + 1));
}
/**
 * is_prime_number - function that returns 1 if the input integer
 * is a prime number, otherwise return 0
 * @n: num
 * Return: output
 */
int is_prime_number(int n)
{
	return (is_prime_num(n, 2));
}
