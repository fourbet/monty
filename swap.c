#include "monty.h"

/**
 * op_swap - swaps the top two elements of the stack
 *
 * @head: head of the stack_t
 * @line_number: line number of the opcode in the file
 *
 * Return: void
 */

void op_swap(stack_t **head, unsigned int line_number)
{
	stack_t *current;
	stack_t *tmp;
	stack_t *before;

	current = *head;
	tmp = *head;
	if (current == NULL || current->prev == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		code_exit = 1;
		return;
	}
	tmp = current;
	current = current->prev;
	before = current->prev;
	tmp->prev = before;
	tmp->next = current;
	current->prev = tmp;
	current->next = NULL;
	*head = current;
}
