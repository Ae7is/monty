#include "monty.h"

/**
 * pop_opcode - removes the top element of the stack
 * @stack: pointer to the stack
 * @line_number: current line number
 */
void pop_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(tmp);
}
