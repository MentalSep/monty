#define _GNU_SOURCE
#include "monty.h"

/**
 * free_stack - free the stack
 * @stack: pointer to the stack
 */
void free_stack(stack_t *stack)
{
	stack_t *tmp = NULL;

	if (!stack)
		return;
	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
/**
 * initData - initialize the global data
 */
void initData(void)
{
	gData.opBuffer = NULL;
	gData.file = NULL;
	gData.line_number = 1;
	gData.stack = NULL;
}

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char *line = NULL;
	size_t len = 0;
	void (*opcode)(stack_t **stack, unsigned int line_number);

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	initData();
	gData.file = fopen(argv[1], "r");
	if (!gData.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &len, gData.file) != -1)
	{
		gData.opBuffer = getInstructions(line);
		if (gData.opBuffer && gData.opBuffer[0])
		{
			opcode = validOpCode(gData.opBuffer[0]);
			if (opcode != NULL)
				opcode(&gData.stack, gData.line_number);
			else
			{
				fprintf(stderr, "L%d: unknown instruction %s\n",
					gData.line_number, gData.opBuffer[0]);
				exit(EXIT_FAILURE);
			}
		}
		gData.line_number++;
		free(gData.opBuffer);
	}
	free(line);
	free_stack(gData.stack);
	fclose(gData.file);
	return (EXIT_SUCCESS);
}
