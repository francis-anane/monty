#include "monty.h"

/**
 * create_node - create new node
 * @n: is a value
 * Return: new node
 */
stack_t *create_node(int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->next = NULL;
	new_node->prev = NULL;

	return (new_node);
}

/**
 * _isdigit - checks for a digit (0 through 9).
 * @c: the character
 * Return: 1 if is digit, or 0 if not.
 */

int _isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

/**
 * free_resources - Frees allocated momory and closes open file streams.
 * @stack: A Stack data structure
 */
void free_resources(stack_t **stack)
{
	stack_t *node = *stack;

	while (node != NULL)
	{
		*stack = (*stack)->next;
		free(node);
		node = *stack;
	}
	if (global_fd.stream)
		fclose(global_fd.stream);
	if (global_fd.line)
		free(global_fd.line);
}
