#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TARGET 2772
#define LEN 33

/**
 * main - generates a random valid password for 101-crackme
 *
 * Return: Always 0.
 */
int main(void)
{
int i, sum, last;
char password[LEN + 1];

srand(time(NULL));

sum = 0;
for (i = 0; i < LEN - 1; i++)
{
password[i] = (rand() % 94) + 33;
sum += password[i];
}

last = TARGET - sum;
while (last < 33 || last > 126)
{
sum -= password[0];
password[0] = (rand() % 94) + 33;
sum += password[0];
last = TARGET - sum;
}

password[LEN - 1] = last;
password[LEN] = '\0';

printf("%s", password);

return (0);
}
