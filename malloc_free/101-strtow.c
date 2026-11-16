#include "main.h"
#include <stdlib.h>

/**
 * count_words - counts the words in a string
 * @str: the string
 *
 * Return: number of words
 */
static int count_words(char *str)
{
	int i, count = 0, in_word = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (str[i] == ' ')
			in_word = 0;
	}

	return (count);
}

/**
 * free_words - frees an array of strings built so far
 * @words: the array
 * @n: number of words already allocated
 */
static void free_words(char **words, int n)
{
	int i;

	for (i = 0; i < n; i++)
		free(words[i]);
	free(words);
}

/**
 * strtow - splits a string into words
 * @str: the string to split
 *
 * Return: array of words ending with NULL, or NULL on failure
 */
char **strtow(char *str)
{
	char **words;
	int i = 0, w = 0, start, len, k, count;

	if (str == NULL || str[0] == '\0')
		return (NULL);

	count = count_words(str);
	if (count == 0)
		return (NULL);

	words = malloc(sizeof(char *) * (count + 1));
	if (words == NULL)
		return (NULL);

	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			start = i;
			while (str[i] != '\0' && str[i] != ' ')
				i++;
			len = i - start;
			words[w] = malloc(sizeof(char) * (len + 1));
			if (words[w] == NULL)
			{
				free_words(words, w);
				return (NULL);
			}
			for (k = 0; k < len; k++)
				words[w][k] = str[start + k];
			words[w][len] = '\0';
			w++;
		}
		else
			i++;
	}
	words[w] = NULL;

	return (words);
}
