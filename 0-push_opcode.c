#include "monty.h"

/**
 * is_integer - checks if a string is a valid integer
 * @s: the string to check
 * Return: 1 if valid, 0 otherwise
 */
int is_integer(char *s)
{
	int i;

	if (s == NULL)
		return (0);

	i = 0;
	if (s[0] == '-')
		i = 1;
	if (s[i] == '\0')
		return (0);

	for (; s[i] != '\0'; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
	}

	return (1);
}

/**
 * push_opcode - pushes an element to the stack or the queue
 * @stack: pointer to the stack
 * @line_number: current line number
 */
void push_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	stack_t *tail;

	if (!is_integer(current_arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
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
	new->next = NULL;
	if (*stack == NULL)
	{
		*stack = new;
		return;
	}
	if (queue_mode == 0)
	{
		new->next = *stack;
		(*stack)->prev = new;
		*stack = new;
		return;
	}
	tail = *stack;
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = new;
	new->prev = tail;
}
