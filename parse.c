#include "monty.h"

/**
 * parse - parse the buffer to identify the opcodes
 *
 * @buffer: string to parse
 * @head: pointer to a pointer to a stack_t
 *
 * Return: 0(SUCCESS), -1(FAILLURE)
 */
int parse(char *buffer, stack_t **head, int line_number)
{
	int i = 0;
	int digit = 0;
	int res = -1;
	char *opcode = NULL;
	char *arg = NULL;

	opcode = strtok(buffer, "\n\t ");
	if (opcode == NULL)
		return (0);
	if (_strncmp(opcode, "push", _strlen("push")) == 0)
	{
		arg = strtok(NULL, "\n\t ");
		for (i = 0; i < _strlen(arg); i++)
		{
			if (!isdigit(arg[i]))
				digit = -1;
		}
		if (arg == NULL || digit == -1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			return (-1);
		}
		op_push(head, atoi(arg));
		return (0);
	}
	res = exec_opcodes(opcode, head, line_number);
	if (res == -2)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		return (-1);
	}
	else
		return(code_exit);
}
