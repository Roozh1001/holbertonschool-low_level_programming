#include <stdio.h>


void clear_input(void)
{
	int ch;

	while ((ch = getchar()) != '\n' && ch != EOF)
	{
	}
}


int read_number(const char *prompt, double *number)
{
	int status;

	while (1)
	{
		printf("%s", prompt);
		fflush(stdout);
		status = scanf("%lf", number);

		if (status == EOF)
			return (0);

		if (status == 1)
			return (1);

		printf("Invalid number\n");
		clear_input();
	}
}


int main(void)
{
	int choice, status;
	double a, b;

	printf("Simple Calculator\n");

	while (1)
	{
		printf("1) Add\n");
		printf("2) Subtract\n");
		printf("3) Multiply\n");
		printf("4) Divide\n");
		printf("0) Quit\n");

		while (1)
		{
			printf("Choice: ");
			fflush(stdout);
			status = scanf("%d", &choice);

			if (status == EOF)
				return (0);

			if (status == 1 && choice >= 0 && choice <= 4)
				break;

			printf("Invalid choice\n");
			clear_input();
		}

		if (choice == 0)
		{
			printf("Bye!\n");
			break;
		}

		if (!read_number("A: ", &a))
			break;
		if (!read_number("B: ", &b))
			break;

		if (choice == 1)
			printf("Result: %g\n", a + b);
		else if (choice == 2)
			printf("Result: %g\n", a - b);
		else if (choice == 3)
			printf("Result: %g\n", a * b);
		else if (b == 0)
			printf("Error: division by zero\n");
		else
			printf("Result: %g\n", a / b);
	}

	return (0);
}
