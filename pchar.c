#include "monty.h"

/**
 * op_pchar - prints the char at the top of the stack
 *
 * @head: head of a stack_t
 * @line_number: line nbr of the opcode in the read file
 *
 * Return: void
 */

void op_pchar(stack_t **head, unsigned int line_number)
{
	stack_t *current;

	current = *head;
	if (current == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty'\n", line_number);
		code_exit = 1;
		return;
	}
	if (isascii(current->n) == 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		code_exit = 1;
		return;
	}
	printf("%c\n", current->n);
}
