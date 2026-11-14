#include "main.h"

/**
 * set_string - sets the value of a pointer to a char
 * @s: pointer to the pointer to change
 * @to: the new address to store in *s
 */
void set_string(char **s, char *to)
{
	*s = to;
}
