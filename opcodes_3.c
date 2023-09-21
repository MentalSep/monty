#include "monty.h"

/**
 * pchar - print the char at the top of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int tmp = 0;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_stack(*stack);
		fclose(gData.file);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	if (tmp < 0 || tmp > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_stack(*stack);
		fclose(gData.file);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", tmp);
}

/**
 * pstr - print the string starting at the top of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	(void)line_number;
	if (!*stack)
	{
		printf("\n");
		return;
	}
	tmp = *stack;
	while (tmp)
	{
		if (tmp->n <= 0 || tmp->n > 127)
			break;
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}
