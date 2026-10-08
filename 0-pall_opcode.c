#include "monty.h"

/**
 * pall_opcode - prints all values on the stack, top to bottom
 * @stack: pointer to the stack
 * @line_number: current line number (unused)
 */
void pall_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;
	current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
