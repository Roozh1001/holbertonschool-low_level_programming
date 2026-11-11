#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @str: the string to modify
 *
 * Return: a pointer to the modified string
 */
char *cap_string(char *str)
{
	int i = 0;
	int new_word = 1;
	char seps[] = " \t\n,;.!?\"()}{";
	int j;

	while (str[i] != '\0')
	{
		if (new_word && str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 'a' + 'A';

		new_word = 0;
		for (j = 0; seps[j] != '\0'; j++)
		{
			if (str[i] == seps[j])
			{
				new_word = 1;
				break;
			}
		}
		i++;
	}

	return (str);
}
