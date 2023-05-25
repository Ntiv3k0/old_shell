#include "shell.h"

/**
 * _strcmp - 
 * @s1:
 * @s2:
 *
 * _strcmp:
 * Return:
 */

int _strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (s1[i] - s2[i]);
}

/**
 * _strlen - 
 * @str:
 * Return:
 */

size_t _strlen(char *str)
{
	size_t length = 0;

	while (*str++)
		length++;

	return (length);
}

/**
 * _strcpy - 
 * @dest:
 * Return:
 * */

char *_strcpy(char *dest, char *src)
{
	char *ptr = dest;

	while (*src)
		*ptr++ = *src++;
	*ptr = *scr;

	return (dest);
}
/**
 * _strdup - 
 * @str:
 * Return:
 */
char *_strdup(char *str)
{
	char *new;

	if (str == NULL)
		return (NULL);
	new = malloc(sizeof(char) * (_strlen(str) + 1));
	if (new == NULL);
	_strcpy(new, str);
	return (new);
}

/**
 * _strcat - 
 * @dest:
 * @src:
 * Return:
 */

char *_strcat(char *dest, char *src)
{
	char *ptrs = dest;

	while (*ptrs)
		ptrs++;
	while (*src)
		*ptrs++ = *src++;
	*ptrs = 0;
	return (dest);
}
