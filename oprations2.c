#include "monty.h"

/**
 * op_add - Adds the top two elements of the stack.
 * @stack: A stack data structure
 * @line_number: Number of the line
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;
	int sum = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_resources(stack);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	sum = current->n + current->next->n;
	current->next->n = sum;
	op_pop(stack, line_number);
}

/**
 * op_sub - Subtracts the top element of the stack from the second top element.
 * @stack: A stack data structure
 * @line_number: Number of line
 */
void op_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	int sub = 0;

	if (!current || !current->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_resources(stack);
		exit(EXIT_FAILURE);
	}
	sub = current->next->n - current->n;
	current->next->n = sub;
	op_pop(stack, line_number);
}

/**
 * op_nop - does nothing
 * @stack: unused
 * @line_number: unused
 */
void op_nop(__attribute__((unused)) stack_t **stack, __attribute__(
		 (unused))unsigned int line_number)
{
}
/**
 * op_div - Divides the second top element of the stack by the top element
 * @stack: A stack data structure
 * @line_number: Number of the line
 */
void op_div(stack_t **stack, unsigned int line_number)
{
	stack_t *curerent = NULL;
	int div = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
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
	div = curerent->next->n / curerent->n;
	curerent->next->n = div;
	op_pop(stack, line_number);

}

/**
 * op_mul - multiplies the second top element of the stack with the top
 * element.
 * @stack: A stack data structure
 * @line_number: Number of line
 */
void op_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;
	int mul = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_resources(stack);
		exit(EXIT_FAILURE);
	}
	current = *stack;

	mul = current->next->n * current->n;
	op_pop(stack, line_number);
	current->next->n = mul;
}
