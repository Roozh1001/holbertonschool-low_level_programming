#include <unistd.h>

/**
 * main - Entry point
 *
 * Description: Writes a quote to the standard error using write
 *
 * Return: Always 1
 */
int main(void)
{
	char msg[] = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";

	write(2, msg, sizeof(msg) - 1);
	return (1);
}
