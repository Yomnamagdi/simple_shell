#include "shell.h"

/**
 **_memset - fills memory with a const byte
 *@r: the pointer to the memory area
 *@b: the byte to fill *r with
 *@n: the amount of bytes to be filled
 *Return: (s) a pointer to the memory area s
 */
char *_memset(char *r, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		r[i] = b;
	return (r);
}

/**
 * ffree - frees a string of strings
 * @ss: string of strings
 */
void ffree(char **ss)
{
	char **a = ss;

	if (!ss)
		return;
	while (*ss)
		free(*ss++);
	free(a);
}

/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated blocks
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(nw_size));
	if (!nw_size)
		return (free(ptr), NULL);
	if (nw_size == od_size)
		return (ptr);

	p = malloc(nw_size);
	if (!p)
		return (NULL);

	od_size = od_size < nw_size ? od_size : nw_size;
	while (od_size--)
		p[od_size] = ((char *)ptr)[od_size];
	free(ptr);
	return (p);
}
