#include "monty.h"

/**
 * getInstructions - get the instructions from the line
 * @line: line to parse
 * Return: array of instructions
 */
char **getInstructions(char *line)
{
	char **tokens = NULL, *tmp = NULL;
	int i;

	tokens = malloc(sizeof(char *) * 3);
	if (!tokens)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(gData.stack);
		fclose(gData.file);
		exit(EXIT_FAILURE);
	}
	tmp = strtok(line, " \n\t");
	for (i = 0; tmp; i++)
	{
		tokens[i] = tmp;
		tmp = strtok(NULL, " \n\t");
	}
	tokens[i] = NULL;
	return (tokens);
}

#include "monty.h"

/**
 * validOpCode - get the opcode
 * @opCode: opcode
 * Return: pointer to the function
 */
void (*validOpCode(char *opCode)) (stack_t **stack, unsigned int line_number)
{
	instruction_t opCodes[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	int i;

	for (i = 0; opCodes[i].opcode; i++)
		if (strcmp(opCodes[i].opcode, opCode) == 0)
			return (opCodes[i].f);

	return (NULL);
}
