#include "monty.h"

/**
 * op_pstr - prints the string starting at the top of the stack
 *
 * @head: head of a stack_t
 * @line_number: line nbr of the opcode in the read file
 *
 * Return: void
 */

void op_pstr(stack_t **head, unsigned int line_number)
{
	stack_t *current;
	int passed = 0;

	current = *head;
	if (current == NULL)
	{
		fprintf(stderr, "\n");
		return;
	}
	while (current)
	{
		if (current->n == 0)
		{
			printf("\n");
			return;
		}
		if (isascii(current->n) != 0)
		{
			printf("%c", current->n);
			passed = 1;
		}
		else
		{
			printf("\n");
			return;
		}
		current = current->prev;
	}
	if (passed == 1)
		printf("\n");
	(void)line_number;
}
