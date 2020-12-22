#include "monty.h"

/**
 * op_pint - prints the value at the top of the stack
 *
 * @head: head of a stack_t
 * @line_number: line nbr of the opcode in the read file
 *
 * Return: void
 */

void op_pint(stack_t **head, unsigned int line_number)
{
	stack_t *current;

	current = *head;
	if (current == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", current->n);
}
