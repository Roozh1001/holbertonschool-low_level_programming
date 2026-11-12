#include "main.h"

/**
 * print_number - prints an integer
 * @n: the integer to print
 */
void print_number(int n)
{
	int div = 1;
	int digit;

	if (n < 0)
		_putchar('-');

	while (n / div > 9 || n / div < -9)
		div *= 10;

	while (div != 0)
	{
		digit = n / div;
		if (digit < 0)
			digit = -digit;
		_putchar('0' + digit);
		n %= div;
		div /= 10;
	}
}
