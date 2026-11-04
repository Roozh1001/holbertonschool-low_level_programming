#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints all different combinations of two digits,
 * separated by a comma and a space, in ascending order
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int a;
	int b;

	a = 0;
	while (a < 9)
	{
		b = a + 1;
		while (b < 10)
		{
			putchar('0' + a);
			putchar('0' + b);
			if (a != 8)
			{
				putchar(',');
				putchar(' ');
			}
			b++;
		}
		a++;
	}
	putchar('\n');

	return (0);
}
