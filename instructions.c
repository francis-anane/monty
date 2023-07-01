#include "monty.h"
/**
 * exec_instruction - Read file
 * @arg: Argument
 * Return: Nothing
 */
void exec_instruction(char *arg)
{
	int count = 0, result = 0;
	size_t buff_size = 0;
	char *arguments = NULL, *value = NULL;
	stack_t *stack = NULL;

	global_fd.stream = fopen(arg, "r");
	if (global_fd.stream)
	{
		while (getline(&global_fd.line, &buff_size, global_fd.stream) != -1)
		{
			count++;
			arguments = strtok(global_fd.line, " \n\t\r");
			if (arguments == NULL)
			{
				free(arguments);
				continue;
			}
			else if (*arguments == '#')
				continue;
			value = strtok(NULL, " \n\t\r");
			result = get_operation(&stack, arguments, value, count);
			if (result == 1)
				push_err(stack, count);
			else if (result == 2)
				instruct_err(stack, arguments, count);
		}
		free_resources(&stack);
	}
	else
	{
		fprintf(stderr, "Error: Can't open file %s\n", arg);
		exit(EXIT_FAILURE);
	}
}
/**
 * get_operation - function to handle the opcode
 * @stack: A stack data structure
 * @arg: The operational instruction
 * @value: Data for a push operation
 * @count: The line number on which instruction occurres
 * Return: 0 on (success), 1 fail push operation, and 2 for invalid
 * instruction.
 */
int get_operation(stack_t **stack, char *arg, char *value, int count)
{
	int i = 0;

	instruction_t operation[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"sub", op_sub},
		{"nop", op_nop},
		{"div", op_div},
		{"mul", op_mul},
		{"mod", op_mod},
		{"pchar", op_pchar},
		{"pstr", op_pstr},
		{NULL, NULL}
	};

	while (operation[i].opcode)
	{
		if (!strcmp(arg, operation[i].opcode))
		{
			if (!strcmp(arg, "push"))
			{
				if (_isdigit(*value) == 1)
					data = atoi(value);
				else
					return (1);
			}
			operation[i].f(stack, (unsigned int)count);
			break;
		}
		i++;
	}
	if (!operation[i].opcode)
		return (2);

	return (0);
}
