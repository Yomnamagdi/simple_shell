#include "shell.h"

/**
 * list_len - determines length of linked lists
 * @f: ptr to first node
 *
 * Return: size of list
 */
size_t list_len(const list_t *f)
{
	size_t i = 0;

	while (f)
	{
		f = f->next;
		i++;
	}
	return (i);
}

/**
 * list_to_strings - returns an array of strings of the list->str
 * @hed: ptr to first node
 *
 * Return: array of strings
 */
char **list_to_strings(list_t *hed)
{
	list_t *node = hed;
	size_t i = list_len(hed), j;
	char **strs;
	char *str;

	if (!hed || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}


/**
 * print_list - prints all parts of a list_t linked list
 * @t: pointer to first node
 *
 * Return: size of list
 */
size_t print_list(const list_t *t)
{
	size_t i = 0;

	while (t)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(t->str ? t->str : "(nil)");
		_puts("\n");
		t = t->next;
		i++;
	}
	return (i);
}

/**
 * node_starts_with - returns node whose string starts with prefix
 * @node: pointer to list head
 * @prefix: string to match
 * @d: the next char after prefix to match
 *
 * Return: match node or null
 */
list_t *node_starts_with(list_t *node, char *prefix, char d)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((d == -1) || (*p == d)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - gets the index of a node
 * @head: ptr to list head
 * @nde: pointer to the node
 *
 * Return: index of node or -1
 */
ssize_t get_node_index(list_t *head, list_t *nde)
{
	size_t i = 0;

	while (head)
	{
		if (head == nde)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}
