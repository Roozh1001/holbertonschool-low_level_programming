#include <stdio.h>

/**
 * main - prints the first 98 Fibonacci numbers, starting with 1 and 2
 *
 * Return: Always 0.
 */
int main(void)
{
	int count;
	unsigned long a_lo, a_hi, b_lo, b_hi, n_lo, n_hi, limit;

	limit = 10000000000UL;
	a_lo = 1;
	a_hi = 0;
	b_lo = 2;
	b_hi = 0;

	for (count = 0; count < 98; count++)
	{
		if (a_hi > 0)
			printf("%lu%010lu", a_hi, a_lo);
		else
			printf("%lu", a_lo);

		if (count < 97)
			printf(", ");

		n_lo = a_lo + b_lo;
		n_hi = a_hi + b_hi;
		if (n_lo >= limit)
		{
			n_lo -= limit;
			n_hi += 1;
		}
		a_lo = b_lo;
		a_hi = b_hi;
		b_lo = n_lo;
		b_hi = n_hi;
	}

	printf("\n");

	return (0);
}
