#include "main.h"
#include <stdlib.h>

/**
 * _strdup - creates duplicate of a string in a newly alloacted memory
 * @str: pointer to original string
 * Return: pointer to deplicate string
 */
char *_strdup(char *str)
{
	char *dstr;

	unsigned int ln;

	if (str == NULL)
		return (NULL);

	ln = _strlen(str) + 1;
	dstr = malloc(sizeof(char) * ln);

	if (dstr == NULL)
		return (NULL);

	dstr = _memcpy(dstr, str, ln);
	return (dstr);
}

/**
 * _memcpy - copies n characters from memory area src to memory area dest
 * @dest: pointer to the destination memory area
 * where the content is to be copied.
 * @src: pointer to the source of data to be copied
 * @n: the number of bytes to be copied
 * Return: a pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}

/**
 * _strlen - returns the length of a string
 * @s: the string to be measured
 *
 * Return: the actual length of the string
 */

int _strlen(char *s)
{
	int len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

/**
 * _strcmp - compares ascii values of two strings
 * @s1: 1st string
 * @s2: 2nd string
 *
 * Return: three different values after the comparison
 */

int _strcmp(char *s1, char *s2)
{
	int res, i;

	int sl1, sl2;

	res = 0;
	sl1 = _strlen(s1);
	sl2 = _strlen(s2);

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			res = s1[i] - s2[i];
			break;
		}
	}

	if (res == 0 && sl1 != sl2)
		res = sl1 - sl2;

	return (res);
}

/**
 * _strcat - appends src stringnto dest string
 * @dest: points to destination string
 * @src: points to source string
 *
 * Return: pointer to the resulting string dest
 */
char *_strcat(char *dest, char *src)
{
	char *p;

	p = dest;
	while (*p)
		p++;

	while (*src)
		*p++ = *src++;

	*p = '\0';
	return (dest);
}
