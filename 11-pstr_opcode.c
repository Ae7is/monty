#include "monty.h"

/**
 * pstr_opcode - prints the string starting at the top of the stack
 * @stack: pointer to the stack
 * @line_number: current line number (unused)
 */
void pstr_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;
	current = *stack;

	while (current != NULL && current->n > 0 && current->n <= 127)
	{
		putchar(current->n);
		current = current->next;
	}

	putchar('\n');
}
