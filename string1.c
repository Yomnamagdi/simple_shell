#include "shell.h"

/**
 * _strcpy - copy a string
 * @destination: the destination
 * @source: the source
 * Return: pointer to destination
 */
char *_strcpy(char *destination, char *source)
{
int s = 0;
if (destination == source || source == 0)
return (destination);
while (source[s])
{
destination[s] = source[s];
s++;
}
destination[s] = 0;
return (destination);
}

/**
 * _strdup - duplicate string
 * @strg: the string to duplicate
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *strg)
{
int len = 0;
char *ret;
if (strg == NULL)
return (NULL);
while (*strg++)
len++;
ret = malloc(sizeof(char) * (len + 1));
if (!ret)
return (NULL);
for (len++; len--;)
ret[len] = *--strg;
return (ret);
}

/**
 * _puts - prints  input string
 * @strg: the string to be printed
 * Return: Always 0 .
 */
void _puts(char *strg)
{
int i = 0;
if (!strg)
return;
while (strg[i] != '\0')
{
_putchar(strg[i]);
i++;
}
}

/**
 * _putchar - writes the character y to stdout
 * @y: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char y)
{
static int n;
static char buf[WRITE_BUF_SIZE];
if (y == BUF_FLUSH || n >= WRITE_BUF_SIZE)
{
write(1, buf, n);
n = 0;
}
if (y != BUF_FLUSH)
buf[n++] = y;
return (1);
}
