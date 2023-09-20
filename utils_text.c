#include "text.h"

/**
 * _strlen :- A function that calculates the length by
 *	iterating over each character of the string.
 * @msg: A character which points to the beginning
 *	of the string whose length needs to be calculated.
 * Return:- Length of the string (value of i).
 ***/

int _strlen(char *msg)
{
	int i;

	for (i = 0; msg[i] != '\0';)
		i++;

	return (i);
}

/**
 * _strcat :- It concatenates the characters from the
 *	source string onto the end of the destination string,
 *	modifying the destination string in-place.
 * @dest: A destination string that concatenate.
 * @src: A source string.
 * Return: A pointer to the destination string.
 ***/

char *_strcat(char *dest, const char *src)
{
	char *ptr = dest;

	while (*ptr != '\0')
		ptr++;

	while (*src != '\0')
	{
		*ptr = *src;
		ptr++;
		src++;
	}

	*ptr = '\0';

	return (dest);
}

/**
 * _strcpy - A function that copy a string to another.
 * @dest: Destination for copy.
 * @src: Source for copy.
 * Return: The value of destination.
 ***/

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];

	dest[i] = '\0';

	return (dest);
}

/**
 ** _strdup - A Pointer to a newly allocated space in memory.
 ** @str: A string to copy.
 ** Return: A value of (dest) string which copied.
 ***/

char *_strdup(char *str)
{
	int size, i;
	char *dest;

	if (str == NULL)
		return (NULL);

	size = _strlen(str) + 1;
	dest = malloc(size * sizeof(char));
	if (dest == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		*(dest + i) = *(str + i);

	return (dest);
}

/**
 * _strcmp - The function takes two arguments to Compare
 *	two strings (s1),(s2).
 * @s1: String 1 to compared.
 * @s2: String 2 to compared.
 * Return: The difference between the characters.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}
