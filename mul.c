#include "monty.h"

/**
 * op_mul - multiplies the seconde top element of the stack by the top
 *
 * @head: head of a stack_t
 * @line_number: line nbr of the opcode in the read file
 *
 * Return: void
 */

void op_mul(stack_t **head, unsigned int line_number)
{
	stack_t *current;
	stack_t *previous;
	int res = 0;

	current = *head;
	if (current == NULL || current->prev == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		code_exit = -1;
		return;
	}
	previous = current->prev;
	res = previous->n * current->n;
	previous->n = res;
	previous->next = NULL;
	free(current);
	*head = previous;
}
