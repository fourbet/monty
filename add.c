#include "monty.h"

/**
 * op_add - adds the top two elements of the stack
 *
 * @head: head of a stack_t
 * @line_number: line nbr of the opcode in the read file
 *
 * Return: void
 */

void op_add(stack_t **head, unsigned int line_number)
{
	stack_t *current;
	stack_t *previous;
	int res = 0;

	current = *head;
	if (current == NULL || current->prev == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		code_exit = 1;
		return;
	}
	previous = current->prev;
	res = current->n + previous->n;
	previous->n = res;
	previous->next = NULL;
	free(current);
	*head = previous;
}
