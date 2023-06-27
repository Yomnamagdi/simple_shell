#include "shell.h"

/**
 * **strtow - splits a string into words. Repeat delimiters are not important
 * @st: the input string
 * @de: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow(char *st, char *de)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (st == NULL || st[0] == 0)
		return (NULL);
	if (!de)
		de = " ";
	for (i = 0; st[i] != '\0'; i++)
		if (!is_delim(st[i], de) && (is_delim(st[i + 1], de) || !st[i + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (is_delim(st[i], de))
			i++;
		k = 0;
		while (!is_delim(st[i + k], de) && st[i + k])
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = st[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

/**
 * **strtow2 - divides a string into words
 * @st: the input string
 * @de: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *st, char de)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (st == NULL || st[0] == 0)
		return (NULL);
	for (i = 0; st[i] != '\0'; i++)
		if ((st[i] != d && st[i + 1] == de) ||
		    (st[i] != de && !st[i + 1]) || st[i + 1] == de)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (st[i] == de && st[i] != de)
			i++;
		k = 0;
		while (st[i + k] != de && st[i + k] && st[i + k] != de)
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = st[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}
