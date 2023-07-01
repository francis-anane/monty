#include "monty.h"

/**
 * push_err - Prints error message for invalid push operations and exit
 * @stack: A stack data structure
 * @count: The line on which the instruction occurred
 */
void push_err(stack_t *stack, int count)
{
	fprintf(stderr, "L%u: usage: push integer\n", count);
	free_resources(&stack);
	exit(EXIT_FAILURE);
}

/**
 * instruct_err - Prints error message for invalid instructions and exit
 * @stack: A stack data structure
 * @count: The line on which the instruction occurred
 * @item: The instruction give on the line
 */
void instruct_err(stack_t *stack, char *count, int item)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", item, count);
	free_resources(&stack);
	exit(EXIT_FAILURE);
}
