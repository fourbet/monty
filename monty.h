#ifndef MONTY_H
#define MONTY_H

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>

extern int code_exit;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int _strlen(char *s);
char *_strcat(char *dest, char *src);
int exec_opcodes(char *opcode, stack_t **stack, int number_line);
int parse(char *buffer, stack_t **stack, int number_line);
int _strncmp(char *s1, char *s2, int n);
void op_push(stack_t **stack, int arg);
void free_stack(stack_t *head);
void op_pall(stack_t **head, unsigned int line_number);
void op_pint(stack_t **head, unsigned int line_number);
void op_nop(stack_t **stack, unsigned int line_number);
void op_pop(stack_t **head, unsigned int line_number);
void op_swap(stack_t **head, unsigned int line_number);
void op_add(stack_t **head, unsigned int line_number);
void op_sub(stack_t **head, unsigned int line_number);
void op_div(stack_t **head, unsigned int line_number);
void op_mul(stack_t **head, unsigned int line_number);
void op_mod(stack_t **head, unsigned int line_number);
void op_pchar(stack_t **head, unsigned int line_number);
void op_pstr(stack_t **head, unsigned int line_number);
int check_integer(char *arg);
#endif
