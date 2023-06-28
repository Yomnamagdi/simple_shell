#include "shell.h"

/**
 * _erratoi - convert a string to integer
 * @s: the string to be converted
 * Return: 0 if no numbers in string, converted number or
 *       -1 on error
 */
int _erratoi(char *s)
{
int i = 0;
unsigned long int results = 0;
if (*s == '+')
s++;
for (i = 0;  s[i] != '\0'; i++)
{
if (s[i] >= '0' && s[i] <= '9')
{
results *= 10;
results += (s[i] - '0');
if (results > INT_MAX)
return (-1);
}
else
return (-1);
}
return (results);
}

/**
 * print_error - print an error message
 * @info: the parameter & return info struct
 * @estrg: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void print_error(info_t *info, char *estrg)
{
_eputs(info->fname);
_eputs(": ");
print_d(info->line_count, STDERR_FILENO);
_eputs(": ");
_eputs(info->argv[0]);
_eputs(": ");
_eputs(estrg);
}

/**
 * print_d - func print a decimal integer number base 10
 * @input: the input
 * @filedescriptor: the filedescriptor to write to
 * Return: number of characters printed
 */
int print_d(int input, int filedescriptor)
{
int (*__putchar)(char) = _putchar;
int i, count = 0;
unsigned int _abs_, current;
if (filedescriptor == STDERR_FILENO)
__putchar = _eputchar;
if (input < 0)
{
_abs_ = -input;
__putchar('-');
count++;
}
else
_abs_ = input;
current = _abs_;
for (i = 1000000000; i > 1; i /= 10)
{
if (_abs_ / i)
{
__putchar('0' + current / i);
count++;
}
current %= i;
}
__putchar('0' + current);
count++;
return (count);
}

/**
 * convert_number - converter function, a clone of itoa
 * @numb: number
 * @base: base
 * @flag: argument flags
 *
 * Return: string
 */
char *convert_number(long int numb, int base, int flag)
{
static char *array;
static char buffer[50];
char sign = 0;
char *ptr;
unsigned long n = numb;
if (!(flag & CONVERT_UNSIGNED) && numb < 0)
{
n = -numb;
sign = '-';
}
array = flag & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
ptr = &buffer[49];
*ptr = '\0';
do {
*--ptr = array[n % base];
n /= base;
}
{
	while
(n != 0);
{
if (sign)
*--ptr = sign;
}
return (ptr);
}

/**
 * remove_comments - function replaces first instance of '#' with '\0'
 * @buff: address of the string to modify
 * Return: Always 0;
 */
void remove_comments(char *buff)
{
int i;
for (i = 0; buff[i] != '\0'; i++)
if (buff[i] == '#' && (!i || buff[i - 1] == ' '))
{
buff[i] = '\0';
break;
}
}
