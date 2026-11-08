#include <stdio.h>

/**
 * main - Display a calculator menu with addition and subtraction.
 *
 * Return: Always 0.
 */
int main(void)
{
	int choice;
	double a, b;

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
		{
			printf("Invalid choice\n");
			continue;
		}

		if (choice == 1 || choice == 2)
		{
			printf("A: ");
			fflush(stdout);
			if (scanf("%lf", &a) != 1)
				break;

			printf("B: ");
			fflush(stdout);
			if (scanf("%lf", &b) != 1)
				break;

			if (choice == 1)
				printf("Result: %g\n", a + b);
			else
				printf("Result: %g\n", a - b);
		}
	}

	return (0);
}
