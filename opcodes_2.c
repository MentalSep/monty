#include "monty.h"

/**
 * add - add the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 */
void add(stack_t **stack, unsigned int line_number)
{
	int tmp = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack(*stack);
		fclose(gData.file);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n + (*stack)->next->n;
	pop(stack, line_number);
	(*stack)->n = tmp;
}
