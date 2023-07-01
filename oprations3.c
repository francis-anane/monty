#include "monty.h"

/**
 * op_mod - computes the rest of the division of the second top element of
 * the stack by top element.
 * @stack: A stack data structure
 * @line_number: Number of line
 */
void op_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *curerent = NULL;
	int div = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_resources(stack);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_resources(stack);
		exit(EXIT_FAILURE);
	}
	curerent = *stack;
	div = curerent->next->n % curerent->n;
	curerent->next->n = div;
	op_pop(stack, line_number);
}

/**
 * op_pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: A stack data structure
 * @line_number: Number of line
 */
void op_pchar(stack_t **stack, unsigned int line_number)
{
	int num = 0;

	if (!*stack || !stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_resources(stack);
		exit(EXIT_FAILURE);
	}

	num = (*stack)->n;
	if (num < 0 || num > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_resources(stack);
		exit(EXIT_FAILURE);
	}
	putchar(num);
	putchar(10);
}

/**
 * op_pstr - prints the string starting at the top of the stack, followed
 * by a new line.
 * @stack: A stack data structure
 * @line_number: Number of line
 */
void op_pstr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *current = *stack;

	while (current && current->n)
	{
		if (current->n < 32 || current->n > 127)
			break;
		printf("%c", current->n);
		current = current->next;
	}
	putchar(10);
}
