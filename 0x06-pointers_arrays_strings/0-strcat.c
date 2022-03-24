#include "main.h"
/**
 * _strcat - function that concatenates two strings.
 * @dest: destination of concat
 * @src: source array to concat
 * Return: char value
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	i++;
	return (dest);
}
