#include "monty.h"

/**
 * op_pall - prints all the values on the stack starting from the top
 *
 * @head: head of a stack_t
 * @line_number: line number of the opcode in the file
 *
 * Return: void
 */

void op_pall(stack_t **head, unsigned int line_number)
{
	stack_t *current;

	current = *head;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->prev;
	}
	(void)line_number;
}
