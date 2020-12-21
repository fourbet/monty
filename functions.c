#include "monty.h"

/**
 * _strlen - returns the length of a string
 * @s: pointer to a char
 *
 * Return: int, the length
 */

int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * _strcat - Write a function that concatenates two strings.
 * @dest: destination, pointer to a char
 * @src: source, pointer to a char
 *
 * Return: char
 */

char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
/**
 * free_stack - frees a stack
 *
 * @head: pointer to a stack
 *
 * Return: void
 */

void free_stack(stack_t *head)
{
	stack_t *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
