#include "main.h"
/**
 * cap_string - function that capitalizes all words of a string.
 * @s: string
 * Return: output
 */
char *cap_string(char *s)
{
	int i = 0;

	if (s[i] >= 97 && s[i] <= 122)
	{
		s[i] -= 32;
	}
	while (s[i] != '\0')
	{
		if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'
		    || s[i] == ',' || s[i] == ';' || s[i] == '.'
		    || s[i] == '!' || s[i] == '?' || s[i] == '"'
		    || s[i] == '(' || s[i] == ')' || s[i] == '{'
		    || s[i] == '}')
		{
			if (s[i + 1] >= 97 && s[i + 1] <= 122)
			{
				s[i + 1] -= 32;
			}
		}
		i++;
	}
	return (s);
}
