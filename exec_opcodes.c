#include "monty.h"

/**
 * _strncmp - compares two stringds
 * @s1: pointer to a char
 * @s2: pointer to a char
 * @n: size
 *
 * Return: int
 */
int _strncmp(char *s1, char *s2, int n)
{
	int i = 0;
	int count = 0;

	if (s1 == NULL && s2 == NULL)
		return (-1);

	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if (s1[i] == s2[i])
		{
			count++;
		}
		else
			return (s1[i] - s2[i]);
		i++;
	}
	if (count == n)
		return (0);
	else
		return (-1);
}
/**
 * exec_opcodes - executes the right function according to the opcode
 *
 * @opcode: string
 * @stack: doubly linked list
 *
 * Return: 0(SUCCESS)
 */
int exec_opcodes(char *opcode, stack_t **stack)
{
	instruction_t instr[] = {{"pall", op_pall}, {"pint", op_pint}, {NULL, NULL}};
	int i = 0;

	if (opcode == NULL)
		return (-1);
	for (i = 0; instr[i].opcode != NULL; i++)
	{
		if (_strncmp(opcode, instr[i].opcode, _strlen(instr[i].opcode)) == 0)
		{
			instr[i].f(stack, line_number);
			return (0);
		}
	}
	return (-1);
}
