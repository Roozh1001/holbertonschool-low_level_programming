#include "main.h"

/**
 * infinite_add - adds two numbers
 * @n1: first number (string of digits)
 * @n2: second number (string of digits)
 * @r: buffer that stores the result
 * @size_r: size of the buffer
 *
 * Return: pointer to the result, or 0 if it does not fit in r
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i = 0;
	int j = 0;
	int k, sum;
	int carry = 0;

	while (n1[i])
		i++;
	while (n2[j])
		j++;
	i--;
	j--;

	k = size_r - 1;
	r[k] = '\0';

	while (i >= 0 || j >= 0 || carry)
	{
		k--;
		if (k < 0)
			return (0);

		sum = carry;
		if (i >= 0)
			sum += n1[i--] - '0';
		if (j >= 0)
			sum += n2[j--] - '0';

		r[k] = (sum % 10) + '0';
		carry = sum / 10;
	}

	return (r + k);
}
