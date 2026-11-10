#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: the string to convert
 *
 * Return: the converted number, or 0 if there are no digits
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int n = 0;
	int found = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-' && !found)
			sign = -sign;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			found = 1;
			n = n * 10 - (s[i] - '0');
		}
		else if (found)
			break;
		i++;
	}

	if (sign > 0)
		return (-n);

	return (n);
}
