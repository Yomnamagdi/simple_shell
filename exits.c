#include "shell.h"

/**
 **_strncpy - copya string
 *@destination: the destination string to be copied to
 *@source: the source string
 *@charAmount: the amount of char to be copied
 *Return: concatenated string
 */
char *_strncpy(char *destination, char *source, int charAmount)
{
int i, j;
char *s = destination;
i = 0;
while (source[i] != '\0' &&  i < charAmount - 1)
{
destination[i] = source[i];
i++;
}
if (i < charAmount)
{
j = i;
while (j < charAmount)
{
destination[j] = '\0';
j++;
}
}
return (s);
}
/**
 **_strncat - concatenates two strings
 *@destination: the first string
 *@source: the second string
 *@charAmount: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *destination, char *source, int charAmount)
{
int i, j;
char *s = destination;
i = 0;
j = 0;
while (destination[i] != '\0')
i++;
while (source[j] != '\0' && j < charAmount)
{
destination[i] = source[j];
i++;
j++;
}
if (j < charAmount)
destination[i] = '\0';
return (s);
}
/**
 **_strchr - locate a char in a string
 *@strg: the string to be parsed
 *@charr: the character to look for
 *Return: (strg) a pointer to the memory area s
 */
char *_strchr(char *strg, char charr)
{
do {
if (*strg == charr)
return (strg);
} while (*strg++ != '\0');
return (NULL);
}

