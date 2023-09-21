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
 * checkMode - check the mode
 * Return: 1 if mode is found, 0 otherwise
 */
int checkMode(void)
{
	if (strcmp(gData.opBuffer[0], "stack") == 0)
	{
		gData.mode = STACKMODE;
		return (1);
	}
	else if (strcmp(gData.opBuffer[0], "queue") == 0)
	{
		gData.mode = QUEUEMODE;
		return (1);
	}
	return (0);
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
	gData.mode = STACKMODE;
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
			if (checkMode())
				goto jump;
			opcode = validOpCode(gData.opBuffer[0]);
			if (opcode != NULL)
				opcode(&gData.stack, gData.line_number);
			else
			{
				fprintf(stderr, "L%d: unknown instruction %s\n",
					gData.line_number, gData.opBuffer[0]);
				free(gData.opBuffer), free(line), free_stack(gData.stack);
				fclose(gData.file);
				exit(EXIT_FAILURE);
			}
		}
jump:
		gData.line_number++, free(gData.opBuffer);
	}
	free(line), fclose(gData.file), free_stack(gData.stack);
	return (EXIT_SUCCESS);
}
