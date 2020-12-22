#include "monty.h"

/**
 * op_rotr - rotates the stack to the bottom
 *
 * @head: head of the stack_t
 * @line_number: line number of the opcode in the file
 *
 * Description: the last element becomes the top element
 *
 * Return: void
 */

void op_rotr(stack_t **head, unsigned int line_number)
{
	stack_t *current;
	stack_t *top;
	stack_t *previous;

	current = *head;
	if (current == NULL || current->prev == NULL)
	{
		return;
	}
	top = current;
	while (current->prev)
	{
		previous = current;
		current = current->prev;
	}
	top->next = current;
	previous->prev = NULL;
	current->prev = top;
	current->next = NULL;
	*head = current;
	(void)line_number;
}
