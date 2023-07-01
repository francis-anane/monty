#include "monty.h"

int data;
/**
 * op_push - Add element to stack data structure.
 * @stack: Ponter to the stack data structure to perform operations on.
 * @line_number: not used.
 */
void op_push(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *new_node = NULL;

	new_node = create_node(data);

	new_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}
/**
 * op_pall - Display elements of a stack data structure.
 * @stack: Ponter to the stack data structure to
 * perform operations on.
 * @line_number: not used
 */
void op_pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *current = NULL;

	current = *stack;

	while (current != NULL)
	{
		fprintf(stdout, "%d\n", current->n);
		current = current->next;
	}
}

/**
 * op_pint - prints the value at the top of the stack.
 * @stack: A stack data structure
 * @line_number: Number of the line
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_resources(stack);
		exit(EXIT_FAILURE);
	}
	else
		fprintf(stdout, "%d\n", (*stack)->n);
}
/**
 * op_swap -Swaps the top two elements of the stack.
 * @stack: A stack data structure
 * @line_number: Number of the line
 */

void op_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	int tmp = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_resources(stack);
		exit(EXIT_FAILURE);
	}
	tmp = current->n;
	current->n = current->next->n;
	current->next->n = tmp;
}
/**
 * op_pop - Removes the top element of the stack.
 * @stack: A stack data structure
 * @line_number: Number of the line
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;

	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_resources(stack);
		exit(EXIT_FAILURE);
	}

	current = *stack;

	*stack = current->next;
	if (current->next != NULL)
		current->next->prev = current->prev;
	free(current);
}
