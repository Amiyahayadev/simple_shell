#include "main.h"

/**
 * _strcpy - Copies a string to a buffer
 * @dest: Buffer to copy to
 * @src: String to copy
 *
 * Return: Pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strncmp - compares ascii values of two strings up to n characters
 * @s1: 1st string
 * @s2: 2nd string
 * @n: highest number of characters to compare
 * Return: three different values after the comparison
 */
int _strncmp(char *s1, char *s2, size_t n)
{
	int res = 0;
	size_t i;

	for (i = 0; i < n && (s1[i] != '\0' || s2[i] != '\0'); i++)
	{
		if (s1[i] != s2[i])
		{
			res = s1[i] - s2[i];
			break;
		}
	}
	return (res);
}
