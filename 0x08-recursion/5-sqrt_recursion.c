#include "main.h"
/**
 * _sqrt_recur - helper function
 * @n: num
 * @x: num
 * Return: output
 */
int _sqrt_recur(int n, int x)
{
	if (x * x == n)
	{
		return (x);
	}
	else if (x * x > n)
	{
		return (-1);
	}
	return (_sqrt_recur(n, x + 1));
}
/**
 * _sqrt_recursion - function that returns the natural square root of a number
 * @n: num
 * Return: square root of a number
 */
int _sqrt_recursion(int n)
{
	return (_sqrt_recur(n, 0));
}
