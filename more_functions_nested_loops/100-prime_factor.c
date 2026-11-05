#include <stdio.h>

/**
 * main - prints the largest prime factor of 612852475143
 *
 * Return: Always 0.
 */
int main(void)
{
	unsigned long n, i, largest;

	n = 612852475143UL;
	largest = 1;

	for (i = 2; i * i <= n; i++)
	{
		while (n % i == 0)
		{
			largest = i;
			n /= i;
		}
	}

	if (n > 1)
		largest = n;

	printf("%lu\n", largest);

	return (0);
}
