#include "monty.h"

/**
 * parse - parse the buffer to identify the opcodes
 *
 * @buffer: string to parse
 * @head: pointer to a pointer to a stack_t
 * @line_number: int
 *
 * Return: 0(SUCCESS), -1(FAILLURE)
 */
int parse(char *buffer, stack_t **head, int line_number)
{
	int digit = 0, res = -1;
	char *opcode = NULL, *arg = NULL;

	opcode = strtok(buffer, "\n\t ");
	if (opcode == NULL || _strncmp(opcode, "#", 1) == 0)
		return (0);
	if (_strncmp(opcode, "push", _strlen("push")) == 0)
	{
		arg = strtok(NULL, "\n\t ");
		if (arg != NULL)
		{
			digit = check_integer(arg);
		}
		if (arg == NULL || digit == -1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			code_exit = -1;
			return (code_exit);
		}
		op_push(head, atoi(arg));
		return (0);
	}
	res = exec_opcodes(opcode, head, line_number);
	if (res == -2)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		code_exit = -1;
	}
	return (code_exit);
}
/**
 * check_integer - checks if the string contains only integer
 *
 * @arg: string
 *
 * Return: 0 (SUCCESS), -1 (FAILURE)
 */

int check_integer(char *arg)
{
	int digit = 0;
	int i = 0;

	for (i = 0; i < _strlen(arg); i++)
	{
		if (i == 0)
		{
			if (!isdigit(arg[0]) && arg[0] != '-')
				digit = -1;
		}
		else
		{
			if (!isdigit(arg[i]))
				digit = -1;
		}
	}
	return (digit);
}
