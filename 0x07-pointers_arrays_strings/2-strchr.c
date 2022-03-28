#include "main.h"
/**
 *_strchr - locates a character in a string
 * @s: string to locate char
 * @c: character to find
 *Return: a pointer to the first occurrence of character c in the string s
 *or NULL if character is not found
 */
char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == c)
		{
			return (s + i);
		}
	}
	if (s[i] == c)
		return (s + i);
	return (0);
}
