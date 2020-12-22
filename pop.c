#include "monty.h"

/**
 * op_pop - removes the top element of the stack
 *
 * @head: head of the stack_t
 * @line_number: line number of the opcode in the file
 *
 * Return: void
 */

void op_pop(stack_t **head, unsigned int line_number)
{
	stack_t *current;
	stack_t *tmp;

	current = *head;
	if (current == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		code_exit = 1;
		return;
	}
	tmp = current->prev;
	*head = tmp;
	free(current);
}
