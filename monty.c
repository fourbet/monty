#include "monty.h"

unsigned int line_number = 0;
/**
 * main - monty
 * @ac: number of arguments
 * @av: array of char (arguments)
 *
 * Return: 0 (SUCESS)
 */

int main(int ac, char **av)
{
	FILE *fd_read;
	char *s;
	int opcode;
	char *buffer = NULL;
	ssize_t bufsize = 0;
	stack_t *head = NULL;

	if (ac != 2)
	{
		s = "USAGE: monty file\n";
		write(STDERR_FILENO, s, _strlen(s));
		exit(EXIT_FAILURE);

	}
	fd_read = fopen(av[1], "r");
	if (fd_read == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		fclose(fd_read);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &bufsize, fd_read) != -1)
	{
		line_number++;
		opcode = parse(buffer, &head);
		if (opcode == -1)
		{
			free(buffer);
			fclose(fd_read);
			exit(EXIT_FAILURE);
		}
	}
	free(buffer);
	free_stack(head);
	fclose(fd_read);
	return (0);
}
