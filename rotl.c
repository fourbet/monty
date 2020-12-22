#include "monty.h"

/**
 * op_rotl - rotates the stack to the top
 *
 * @head: head of the stack_t
 * @line_number: line number of the opcode in the file
 *
 * Description: the top element becomes the last one
 *
 * Return: void
 */

void op_rotl(stack_t **head, unsigned int line_number)
{
	stack_t *current;
	stack_t *top;
	stack_t *before;

	current = *head;
	if (current == NULL || current->prev == NULL)
	{
		return;
	}
	top = current;
	before = current->prev;
	while (current->prev)
	{
		current = current->prev;
	}
	current->prev = top;
	top->next = current;
	top->prev = NULL;
	before->next = NULL;
	*head = before;
	(void)line_number;
}
