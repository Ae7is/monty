#include "monty.h"

char *current_arg;
int queue_mode;

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
 * get_op_func - finds the function matching an opcode
 * @opcode: the opcode name
 * Return: pointer to the function, or NULL if the opcode is unknown
 */
op_func get_op_func(char *opcode)
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
		{"pchar", pchar_opcode},
		{"pstr", pstr_opcode},
		{"rotl", rotl_opcode},
		{"rotr", rotr_opcode},
		{"stack", stack_opcode},
		{"queue", queue_opcode},
		{NULL, NULL}
	};
	int i;

	for (i = 0; opcodes[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
			return (opcodes[i].f);
	}

	return (NULL);
}

/**
 * execute_line - parses and executes one line of bytecode
 * @line: the line to execute
 * @stack: pointer to the stack
 * @line_number: current line number, for error messages
 */
void execute_line(char *line, stack_t **stack, unsigned int line_number)
{
	char *opcode;
	op_func f;

	opcode = strtok(line, " \t\n");
	if (opcode == NULL || opcode[0] == '#')
		return;

	current_arg = strtok(NULL, " \t\n");
	f = get_op_func(opcode);
	if (f == NULL)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n",
			line_number, opcode);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	f(stack, line_number);
}

/**
 * run_file - reads a file line by line and executes every line
 * @file: the opened bytecode file
 */
void run_file(FILE *file)
{
	char *line;
	size_t len;
	unsigned int line_number;
	stack_t *stack;

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

	run_file(file);
	fclose(file);

	return (EXIT_SUCCESS);
}
