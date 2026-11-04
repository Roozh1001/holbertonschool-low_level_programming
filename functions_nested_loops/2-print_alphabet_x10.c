#include "main.h"

/**
 * print_alphabet_x10 - Prints 10 times the alphabet in lowercase,
 * each followed by a new line
 *
 * Return: void
 */
void print_alphabet_x10(void)
{
	int line;
	char letter;

	line = 0;
	while (line < 10)
	{
		letter = 'a';
		while (letter <= 'z')
		{
			_putchar(letter);
			letter++;
		}
		_putchar('\n');
		line++;
	}
}
