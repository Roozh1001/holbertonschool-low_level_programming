#include <stdio.h>

/**
 * main - Display a menu and validate the user's choice.
 *
 * Return: Always 0.
 */
int main(void)
{
	int choice;

	printf("Simple Calculator\n");

	while (1)
	{
		printf("1) Add\n");
		printf("2) Subtract\n");
		printf("3) Multiply\n");
		printf("4) Divide\n");
		printf("0) Quit\n");
		printf("Choice: ");
		fflush(stdout);

		if (scanf("%d", &choice) != 1)
			break;

		if (choice == 0)
		{
			printf("Bye!\n");
			break;
		}

		if (choice < 0 || choice > 4)
			printf("Invalid choice\n");
	}

	return (0);
}
