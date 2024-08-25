#include "main.h"

/**
 * _strncmp - Compare up to n characters of two strings
 * @s1: The first string to compare
 * @s2: The second string to compare
 * @n: The number of characters to compare
 *
 * Return: (s1[i] - s2[i]) or 0 if same
 */
int _strncmp(char *s1, const char *s2, int n)
{
	int i = 0;
	
	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	
	if (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		return (s1[i] - s2[i]);
	}
	
	return (0);
}

/**
 *  * _strlen - returns the length of a string
 *   * @s: string
 *    * Return: length
 */
 
 
 /**
 *  * _strcmp - compare string values
 *   * @s1: input value
 *    * @s2: input value
 *     *
 *      * Return: s1[i] - s2[i]
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{			return (s1[i] - s2[i]);
		
		}
		i++;
	}
	return (0);
}

/**
* _strlen - returns the length of a string
* @s: string
*/
 int _strlen(const char *s)
 {
    int len = 0;
    
    while(s[len] != '\0')
    {
        len++;
    }
return (len);
 }

 /**
* _strdup - duplicate to new memory space location
*
* @str: char
*
* Return: 0
*/
char *_strdup(char *str)
{
	char *ptr;
	int len = 0, i = 0, c;

	if (str == NULL)
		return (NULL);

	while (str[i] != '\0')
	{
		len++;
		i++;
	}

	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);

	for (c = 0; c <= len; c++)
	{
		ptr[c] = str[c];
	}

	return (ptr);
}

#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * my_strchr - Checks if a character is in the delimiter string
 * @str: The string to search in
 * @ch: The character to search for
 * Return: 1 if character is found, 0 otherwise
 */
int my_strchr(const char *str, char ch)
{
	while (*str)
	{
		if (*str == ch)
			return (1);
		str++;
	}
	return (0);
}

/**
 * my_strtok - Tokenizes a string
 * @str: The string to tokenize
 * @delim: The delimiter string
 * Return: A pointer to the next token or NULL
 */
char *_strtok(char *str, const char *delim)
{
	static char *buffer;
	char *token;

	if (str)
		buffer = str;
	else if (!buffer)
		return (NULL);

	/*Skip leading delimiters*/
	while (*buffer && my_strchr(delim, *buffer))
		buffer++;

	if (!*buffer)
		return (NULL);

	token = buffer;

	/*Find the end of the token*/
	while (*buffer && !my_strchr(delim, *buffer))
		buffer++;

	if (*buffer)
	{
		*buffer = '\0';
		buffer++;
	}

	return (token);
}