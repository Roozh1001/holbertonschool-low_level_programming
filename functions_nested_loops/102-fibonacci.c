#include <stdio.h>

/**
 * main - prints the first 50 Fibonacci numbers, starting with 1 and 2
 *
 * Return: Always 0.
 */
int main(void)
{
	int i;
	unsigned long a, b, next;

	a = 1;
	b = 2;

	for (i = 0; i < 50; i++)
	{
		printf("%lu", a);

		if (i < 49)
			printf(", ");

		next = a + b;
		a = b;
		b = next;
	}

	printf("\n");

	return (0);
}
