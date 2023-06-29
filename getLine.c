#include "shell.h"


/**
 * input_buf - buffer chained command
 * @info: parameter struct
 * @buff: address of buffer
 * @length: address of len var
 * Return: bytes read
 */
ssize_t input_buf(info_t *info, char **buff, size_t *length)
{
ssize_t r = 0;
size_t len_p = 0;
if (!*length) /* if nothing left in the buffer, fill it */
{
free(*buff);
*buff = NULL;
signal(SIGINT, sigintHandler);
#if USE_GETLINE
r = getline(buf, &len_p, stdin);
#else
r = _getline(info, buff, &len_p);
#endif
if (r > 0)
{
if ((*buff)[r - 1] == '\n')
{
(*buff)[r - 1] = '\0'; /* remove trailing newline */
r--;
}
info->linecount_flag = 1;
remove_comments(*buff);
build_history_list(info, *buff, info->histcount++);
{
*length = r;
info->cmd_buf = buff;
}
}
}
return (r);
}
/**
 * get_input - get a line minus the newline
 * @info: parameter struct
 * Return: bytes read
 */
ssize_t get_input(info_t *info)
{
static char *buff; /* the ';' command chain buffer */
static size_t i, j, length;
ssize_t r = 0;
char **buf_p = &(info->arg), *p;
_putchar(BUF_FLUSH);
r = input_buf(info, &buff, &length);
if (r == -1)
return (-1);
if (length)
{
j = i;
p = buff + i;
check_chain(info, buff, &j, i, length);
while (j < length)
{
if (is_chain(info, buff, &j))
break;
j++;
}
i = j + 1;
if (i >= length)
{
i = length = 0;
info->cmd_buf_type = CMD_NORM;
}
*buf_p = p;
return (_strlen(p));
}
*buf_p = buff;
return (r);
}
/**
 * read_buf - reads a buffer
 * @info: parameter struct
 * @buff: buffer
 * @s: size
 *
 * Return: r
 */
ssize_t read_buf(info_t *info, char *buff, size_t *s)
{
ssize_t r = 0;
if (*s)
return (0);
r = read(info->readfd, buff, READ_BUF_SIZE);
if (r >= 0)
*s = r;
return (r);
}

/**
 * _getline - get the next line of input from STDIN
 * @info: parameter struct
 * @ptr: address of pointer to buffer, preallocated or NULL
 * @lengthh: size of preallocated ptr buffer if not NULL
 * Return: s
 */
int _getline(info_t *info, char **ptr, size_t *lengthh)
{
static char buff[READ_BUF_SIZE];
static size_t i, len;
size_t k;
ssize_t r = 0, s = 0;
char *p = NULL, *new_p = NULL, *c;
p = *ptr;
if (p && lengthh)
s = *lengthh;
if (i == len)
i = len = 0;
r = read_buf(info, buff, &len);
if (r == -1 || (r == 0 && len == 0))
return (-1);
c = _strchr(buff + i, '\n');
k = c ? 1 + (unsigned int)(c - buff) : len;
new_p = _realloc(p, s, s ? s + k : k + 1);
if (!new_p) /* MALLOC FAILURE! */
return (p ? free(p), -1 : -1);
if (s)
_strncat(new_p, buff + i, k - i);
else
_strncpy(new_p, buff + i, k - i + 1);
s ++k - i;
i = k;
p = new_p;
if (lengthh)
*lengthh = s;
*ptr = p;
return (s);
}
/**
 * sigintHandler - blocks ctrl-C
 * @sign_num: the signal number
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sign_num)
{
_puts("\n");
_puts("$ ");
_putchar(BUF_FLUSH);
}
