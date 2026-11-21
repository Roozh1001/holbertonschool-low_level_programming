#include "main.h"

/**
 * _sqrt_helper - tries candidates for the square root recursively
 * @n: the number
 * @i: the current candidate
 *
 * Return: the natural square root of n, or -1 if there is none
 */
int _sqrt_helper(int n, int i)
{
	if (i * i > n)
		return (-1);

	if (i * i == n)
		return (i);

	return (_sqrt_helper(n, i + 1));
}

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: the number
 *
 * Return: the natural square root of n, or -1 if there is none
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);

	return (_sqrt_helper(n, 0));
}
