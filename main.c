#include "monty.h"

char *current_arg;

/**
 * free_stack - frees the entire stack
 * @stack: pointer to the head of the stack
 */
void free_stack(stack_t *stack)
{
	stack_t *tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

/**
 * execute_line - parses and executes one line of bytecode
 * @line: the line to execute
 * @stack: pointer to the stack
 * @line_number: current line number, for error messages
 */
void execute_line(char *line, stack_t **stack, unsigned int line_number)
{
	instruction_t opcodes[] = {
		{"push", push_opcode},
		{"pall", pall_opcode},
		{"pint", pint_opcode},
		{"pop", pop_opcode},
		{"swap", swap_opcode},
		{"add", add_opcode},
		{"nop", nop_opcode},
		{"sub", sub_opcode},
		{"div", div_opcode},
		{"mul", mul_opcode},
		{"mod", mod_opcode},
		{NULL, NULL}
	};
	char *opcode;
	int i;

	opcode = strtok(line, " \t\n");
	current_arg = strtok(NULL, " \t\n");

	if (opcode == NULL || opcode[0] == '#')
		return;

	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	free_stack(*stack);
	exit(EXIT_FAILURE);
}

/**
 * main - entry point for the Monty interpreter
 * @argc: argument count
 * @argv: argument vector
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line;
	size_t len;
	unsigned int line_number;
	stack_t *stack;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	stack = NULL;
	line = NULL;
	len = 0;
	line_number = 0;

	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		execute_line(line, &stack, line_number);
	}

	free(line);
	free_stack(stack);
	fclose(file);

	return (EXIT_SUCCESS);
}
