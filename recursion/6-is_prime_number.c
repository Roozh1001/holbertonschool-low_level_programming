#include "main.h"

/**
 * check_prime - checks recursively if n has a divisor from i upward
 * @n: the number to check
 * @i: the current divisor to try
 *
 * Return: 1 if no divisor is found, otherwise 0
 */
int check_prime(int n, int i)
{
	if (i * i > n)
		return (1);

	if (n % i == 0)
		return (0);

	return (check_prime(n, i + 1));
}

/**
 * is_prime_number - checks if a number is prime
 * @n: the number to check
 *
 * Return: 1 if n is prime, otherwise 0
 */
int is_prime_number(int n)
{
	if (n < 2)
		return (0);

	return (check_prime(n, 2));
}
