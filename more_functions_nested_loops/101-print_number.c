#include "main.h"

/**
 * print_number - prints an integer
 * @n: the integer to print
 */
void print_number(int n)
{
	int div, digit;

	if (n < 0)
		_putchar('-');

	div = 1;
	while (n / div >= 10 || n / div <= -10)
		div *= 10;

	while (div > 0)
	{
		digit = n / div % 10;
		if (digit < 0)
			digit = -digit;
		_putchar(digit + '0');
		div /= 10;
	}
}
