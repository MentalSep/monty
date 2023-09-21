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

/**
 * rotl - rotate the stack to the top
 * @stack: pointer to the stack
 * @line_number: line number
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	int tmp;

	(void)line_number;
	if (!*stack || !(*stack)->next)
		return;
	tmp = (*stack)->n;
	pop(stack, line_number);
	add_dnodeint_end(stack, tmp);
}

/**
 * rotr - rotate the stack to the bottom
 * @stack: pointer to the stack
 * @line_number: line number
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	(void)line_number;
	if (!*stack || !(*stack)->next)
		return;
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = tmp;
}

/**
 * add_dnodeint_end - adds a new node at the end of a stack_t list
 * @head: pointer to the head of the list
 * @n: integer to store in the new node
 *
 * Return: address of the new element, or NULL if it failed
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new, *tmp;

	if (!head)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*head);
		fclose(gData.file);
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->next = NULL;
	if (!*head)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	new->prev = tmp;
	tmp->next = new;

	return (new);
}
