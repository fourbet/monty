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

	current = *head;
	if (current == NULL)
	{
		printf("\n");
		return;
	}
	while (current && isascii(current->n) != 0 && current->n != 0)
	{
		printf("%c", current->n);
		current = current->prev;
	}
	printf("\n");
	(void)line_number;
}
