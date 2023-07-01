#include "monty.h"

fd global_fd = {NULL, NULL};
/**
 * main - Entry point
 * @ac: Argument count
 * @av: Argument vector
 * Return: 0 (success).
 */
int main(int ac, char *av[])
{
	/*check number of arguments to monty*/
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else
		exec_instruction(av[1]);
	return (0);
}
