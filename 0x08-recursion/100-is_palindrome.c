#include "main.h"
/**
 * length - function that returns the length of a string
 * @s: string
 * Return: length of a string
 */
int length(char *s)
{
	if (*s != '\0')
	{
		return (1 + length(s + 1));
	}
	return (0);
}
/**
 * checker - helper function
 * @s: string
 * @x: num
 * Return: output
 */
int checker(char *s, int x)
{
	if (x <= 0)
	{
		return (1);
	}
	if (*s == *(s + x - 1))
	{
		return (checker(s + 1, x - 2));
	}
	else
	{
		return (0);
	}
}
/**
 * is_palindrome - function that returns 1 if a string is a palindrome
 * and 0 if not.
 * @s: string
 * Return: 1 if a string is a palindrome and 0 if not
 */
int is_palindrome(char *s)
{
	int x = length(s);

	return (checker(s, x));
}
