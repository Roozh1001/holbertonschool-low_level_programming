#include <stdio.h>

/**
 * main - prints the sum of the even-valued Fibonacci terms
 * that do not exceed 4,000,000
 *
 * Return: Always 0.
 */
int main(void)
{
	unsigned long a, b, next, sum;

	a = 1;
	b = 2;
	sum = 0;

	while (a <= 4000000)
	{
		if (a % 2 == 0)
			sum += a;

		next = a + b;
		a = b;
		b = next;
	}

	printf("%lu\n", sum);

	return (0);
}
