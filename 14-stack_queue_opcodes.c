#include "monty.h"

/**
 * stack_opcode - sets the format of the data to a stack (LIFO)
 * @stack: pointer to the stack (unused)
 * @line_number: current line number (unused)
 */
void stack_opcode(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	queue_mode = 0;
}

/**
 * queue_opcode - sets the format of the data to a queue (FIFO)
 * @stack: pointer to the stack (unused)
 * @line_number: current line number (unused)
 */
void queue_opcode(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	queue_mode = 1;
}
