#include "shell.h"
/**
 * bfree - frees  pointer ,NULL the address
 * @ptr: address of the pointer to free
 * Return: 1 if freed, or 0.
 */
int bfree(void **ptr)
{
if (ptr && *ptr)
{
free(*ptr);
*ptr = NULL;
return (1);
}
return (0);
}
