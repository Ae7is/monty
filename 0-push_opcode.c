#include "monty.h"

/**
 * push_opcode - pushes an element to the top of the stack
 * @stack: pointer to the stack
 * @line_number: current line number
 */
void push_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int i;

	if (current_arg == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	for (i = 0; current_arg[i] != '\0'; i++)
	{
		if (i == 0 && current_arg[i] == '-' && current_arg[1] != '\0')
			continue;
		if (current_arg[i] < '0' || current_arg[i] > '9')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	new->n = atoi(current_arg);
	new->prev = NULL;
	new->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new;

	*stack = new;
}
