#include "monty.h"

/**
 * rotr_opcode - rotates the stack to the bottom
 * @stack: pointer to the stack
 * @line_number: current line number (unused)
 */
void rotr_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *last;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;

	last = *stack;
	while (last->next != NULL)
		last = last->next;

	last->prev->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}
