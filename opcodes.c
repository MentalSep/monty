#include "monty.h"

/**
 * push - push an element to the stack
 * @stack: pointer to the stack
 * @line_number: line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;
	int n;

	if (!gData.opBuffer[1] || checkNumber(gData.opBuffer[1]))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(*stack);
		fclose(gData.file);
		exit(EXIT_FAILURE);
	}
	n = atoi(gData.opBuffer[1]);
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		fclose(gData.file);
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = NULL;
	new->prev = NULL;
	if (*stack)
	{
		new->next = *stack;
		(*stack)->prev = new;
	}
	*stack = new;
}

/**
 * pall - print all the elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	(void)line_number;
	if (!*stack)
		return;
	tmp = *stack;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pint - print the top element of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_stack(*stack);
		fclose(gData.file);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - remove the top element of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_stack(*stack);
		fclose(gData.file);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	if (tmp->next)
	{
		*stack = tmp->next;
		tmp->next->prev = NULL;
	}
	else
		*stack = NULL;
	free(tmp);
}

/**
 * swap - swap the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(*stack);
		fclose(gData.file);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}
