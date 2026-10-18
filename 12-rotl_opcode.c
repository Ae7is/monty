#include "monty.h"

/**
 * rotl_opcode - rotates the stack to the top
 * @stack: pointer to the stack
 * @line_number: current line number (unused)
 */
void rotl_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	stack_t *last;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;

	first = *stack;
	last = first;
	while (last->next != NULL)
		last = last->next;

	*stack = first->next;
	(*stack)->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
}
