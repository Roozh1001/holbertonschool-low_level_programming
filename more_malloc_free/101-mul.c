#include "main.h"
#include <stdlib.h>

/**
 * error_exit - prints Error and exits with status 98
 */
void error_exit(void)
{
	char *msg = "Error\n";
	int i;

	for (i = 0; msg[i] != '\0'; i++)
		_putchar(msg[i]);
	exit(98);
}

/**
 * str_len - computes the length of a string
 * @s: the string
 *
 * Return: length of s
 */
int str_len(char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;

	return (len);
}

/**
 * is_number - checks that a string contains only digits
 * @s: the string
 *
 * Return: 1 if s is non-empty and only digits, 0 otherwise
 */
int is_number(char *s)
{
	int i;

	if (s[0] == '\0')
		return (0);

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
	}

	return (1);
}

/**
 * multiply - multiplies two numbers given as strings of digits
 * @n1: first number
 * @n2: second number
 * @len1: length of n1
 * @len2: length of n2
 *
 * Return: array of len1 + len2 digits, or NULL if malloc fails
 */
int *multiply(char *n1, char *n2, int len1, int len2)
{
	int *res;
	int i, j, sum;

	res = malloc(sizeof(int) * (len1 + len2));
	if (res == NULL)
		return (NULL);

	for (i = 0; i < len1 + len2; i++)
		res[i] = 0;

	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = len2 - 1; j >= 0; j--)
		{
			sum = (n1[i] - '0') * (n2[j] - '0') + res[i + j + 1];
			res[i + j + 1] = sum % 10;
			res[i + j] += sum / 10;
		}
	}

	return (res);
}

/**
 * main - multiplies two positive numbers
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, exits with 98 on error
 */
int main(int argc, char **argv)
{
	int len1, len2, i = 0, *res;

	if (argc != 3 || !is_number(argv[1]) || !is_number(argv[2]))
		error_exit();

	len1 = str_len(argv[1]);
	len2 = str_len(argv[2]);
	res = multiply(argv[1], argv[2], len1, len2);
	if (res == NULL)
		error_exit();

	while (i < len1 + len2 - 1 && res[i] == 0)
		i++;
	for (; i < len1 + len2; i++)
		_putchar(res[i] + '0');
	_putchar('\n');

	free(res);
	return (0);
}
