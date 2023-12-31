#include "monty.h"

/**
 * getInstructions - get the instructions from the line
 * @line: line to parse
 * Return: array of instructions
 */
char **getInstructions(char *line)
{
	char **tokens = NULL, *tmp = NULL;
	int i, j;

	tokens = malloc(sizeof(char *) * 50);
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
	for (j = 0; j < i; j++)
	{
		if (strcmp(tokens[j], "nop") == 0 || tokens[j][0] == '#')
		{
			tokens[j] = NULL;
			break;
		}
	}
	tokens[i] = NULL;
	return (tokens);
}

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
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", div_},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};
	int i;

	for (i = 0; opCodes[i].opcode; i++)
		if (strcmp(opCodes[i].opcode, opCode) == 0)
			return (opCodes[i].f);

	return (NULL);
}

/**
 * checkNumber - check if the string is a number
 * @str: string to check
 * Return: 0 on success
 */
int checkNumber(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == '-' && i == 0)
			continue;
		if (isdigit(str[i]) == 0)
			return (1);
	}
	return (0);
}
