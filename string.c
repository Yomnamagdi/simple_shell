#include "shell.h"
/**
 * _strlen - returns the length of a string
 * @strg: the string whose length to check
 * Return: length of string
 */
int _strlen(char *strg)
{
int n = 0;
if (!strg)
return (0);
while (*strg++)
n++;
return (n);
}
/**
 * _strcmp -  lexicogarphic comparison of two strangs.
 * @strg1:  first strang
 * @strg2:  second strang
 * Return: negative if strg1 < strg2, positive if strg1 > strg2
 */
int _strcmp(char *strg1, char *strg2)
{
while (*strg1 && *strg2)
{
if (*strg1 != *strg2)
return (*strg1 - *strg2);
strg1++;
strg2++;
}
if (*strg1 == *strg2)
return (0);
else
return (*strg1 < *strg2 ? -1 : 1);
}

/**
 * starts_with - checks if needle starts with haystack
 * @haystack: string to search
 * @needle: the substring to find
 * Return: address of next char of haystack or NULL
 *
 */
char *starts_with(const char *haystack, const char *needle)
{
while (*needle)
if (*needle++ != *haystack++)
return (NULL);
return ((char *)haystack);
}

/**
 * _strcat - concatenates 2 strings
 * @destination: the destination buffer
 * @source: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *destination, char *source)
{
char *ret = destination;
while (*destination)
destination++;
while (*source)
*destination++ = *source++;
*destination = *source;
return (ret);
}
