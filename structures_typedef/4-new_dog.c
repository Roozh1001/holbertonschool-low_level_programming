#include <stdlib.h>
#include "dog.h"

/**
 * _strlen - returns the length of a string
 * @s: the string
 *
 * Return: length of the string
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;

	return (len);
}

/**
 * _strdup - returns a copy of a string in new memory
 * @s: the string to copy
 *
 * Return: pointer to the copy, or NULL if it fails
 */
char *_strdup(char *s)
{
	char *copy;
	int i, len;

	len = _strlen(s);
	copy = malloc(len + 1);
	if (copy == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
		copy[i] = s[i];

	return (copy);
}

/**
 * new_dog - creates a new dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 *
 * Return: pointer to the new dog, or NULL if it fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d;

	if (name == NULL || owner == NULL)
		return (NULL);

	d = malloc(sizeof(dog_t));
	if (d == NULL)
		return (NULL);

	d->name = _strdup(name);
	if (d->name == NULL)
	{
		free(d);
		return (NULL);
	}

	d->owner = _strdup(owner);
	if (d->owner == NULL)
	{
		free(d->name);
		free(d);
		return (NULL);
	}

	d->age = age;

	return (d);
}
