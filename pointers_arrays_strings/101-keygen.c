#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TARGET 2772
#define LEN 36

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
password[i] = (rand() % 26) + 'A';
sum += password[i];
}

last = TARGET - sum;

i = 0;
while (last > 'Z')
{
if (password[i] < 'Z')
{
password[i]++;
sum++;
last--;
}
i = (i + 1) % (LEN - 1);
}
while (last < 'A')
{
if (password[i] > 'A')
{
password[i]--;
sum--;
last++;
}
i = (i + 1) % (LEN - 1);
}

password[LEN - 1] = last;
password[LEN] = '\0';

printf("%s", password);

return (0);
}
