#include "shell.h"

/**
 *_eputs - prints an input string
 * @strg: the string to be printed
 * Return: Nothing
 */
void _eputs(char *strg)
{
int n = 0;
if (!strg)
return;
while (strg[n] != '\0')
{
_eputchar(strg[n]);
n++;
}
}
/**
 * _eputchar - write the char a to stderr
 * @a: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char a)
{
static int i;
static char buf[WRITE_BUF_SIZE];
if (a == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(2, buf, i);
i = 0;
}
if (a != BUF_FLUSH)
buf[i++] = a;
return (1);
}

/**
 * _putfd - writes the character a to given fd
 * @a: The character to print
 * @filedescriptor: The filedescriptor to write to
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char a, int filedescriptor)
{
static int i;
static char buf[WRITE_BUF_SIZE];
if (a == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(filedescriptor, buf, i);
i = 0;
}
if (a != BUF_FLUSH)
buf[i++] = a;
return (1);
}

/**
 *_putsfd - prints an input string
 * @strg: the string to be printed
 * @filedescriptor: the filedescriptor to write to
 * Return: the number of chars put
 */
int _putsfd(char *strg, int filedescriptor)
{
int i = 0;
if (!strg)
return (0);
while (*strg)
{
i += _putfd(*strg++, filedescriptor);
}
return (i);
}
