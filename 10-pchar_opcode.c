#include "monty.h"

/**
 * pchar_opcode - prints the char at the top of the stack
 * @stack: pointer to the stack
 * @line_number: current line number
 */
void pchar_opcode(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n",
			line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}
