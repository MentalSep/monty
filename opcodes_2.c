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

/**
 * sub - subtract the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int tmp = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_stack(*stack);
		fclose(gData.file);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next->n - (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = tmp;
}

/**
 * div_ - divide the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 */
void div_(stack_t **stack, unsigned int line_number)
{
	int tmp = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_stack(*stack);
		fclose(gData.file);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(*stack);
		fclose(gData.file);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next->n / (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = tmp;
}

/**
 * mul - multiply the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int tmp = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_stack(*stack);
		fclose(gData.file);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n * (*stack)->next->n;
	pop(stack, line_number);
	(*stack)->n = tmp;
}

/**
 * mod - compute the modulus of the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int tmp = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_stack(*stack);
		fclose(gData.file);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(*stack);
		fclose(gData.file);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next->n % (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = tmp;
}
