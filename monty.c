#include "monty.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char buffer[MAX_LINE_CHARS];
int arr[MAX_LINE_CHARS];

instruction_t operations[] = {
	{"push", &_push},
	{"pall", &_pall},
	{"pint", &_pint},
	{"swap", &_swap},
	{"add", &_add},
	{"sub", &_sub},
	{"div", &_div},
	{"mul", &_mul},
	{"mod", &_mod},
	{"pchar", &_pchar},
	{NULL, NULL}};

stack_t *stack = NULL;
unsigned int line = 1;
/**
 * main - monty interpreter
 * @argc: number of cmd args
 * @argv: array of strings of the cmd args
 * Return: zero if success
*/
int main(int argc, char **argv)
{
	FILE *fd;
	char **strings = NULL;
	char **tokens = NULL;
	int co = 0, t;
	unsigned int j;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	strings = malloc(MAX_LINES * sizeof(char *));
	if (strings == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	while (fgets(buffer, MAX_LINE_CHARS, fd))
	{
		if (line >= MAX_LINES)
		{
			fprintf(stderr, "Error: Exceeded maximum number of lines\n");
			exit(EXIT_FAILURE);
		}
		strings[line - 1] = malloc(strlen(buffer) + 1);
		if (strings[line - 1] == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		strcpy(strings[line - 1], buffer);

		tokens = malloc(MAX_LINE_CHARS * sizeof(char *));
		if (tokens == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}

		t = 0;
		tokens[t] = strtok(buffer, " \t\n");
		while (tokens[t] != NULL)
		{
			if (tokens[t][0] != '\0' && !isspace(*tokens[t]))
			{
				if (strcmp(tokens[t], "push") == 0)
				{
					t++;
					tokens[t] = strtok(NULL, " \t\n");
					if (tokens[t] != NULL)
					{
						char *endptr;
						long num = strtol(tokens[t], &endptr, 10);
						if (*endptr == '\0' && !isspace(*tokens[t]))
						{
							while (operations[co].opcode != NULL)
							{
								if (strcmp(operations[co].opcode, "push") == 0)
								{
									operations[co].f(&stack, num);
									break;
								}
								co++;
							}
							co = 0;
						}
						else
						{
							fprintf(stderr, "Error: Invalid number at line %d\n", line);
							exit(EXIT_FAILURE);
						}
					}
					else
					{
						fprintf(stderr, "Error: No argument provided for push at line %d\n", line);
						exit(EXIT_FAILURE);
					}
				}
			}
			if (strcmp(tokens[t], "pall") == 0)
			{
				while (operations[co].opcode != NULL)
				{
					if (strcmp(operations[co].opcode, "pall") == 0)
					{
						operations[co].f(&stack, line);
						break;
					}
					co++;
				}
				co = 0;
			}
			else if (strcmp(tokens[t], "pint") == 0)
			{
				while (operations[co].opcode != NULL)
				{
					if (strcmp(operations[co].opcode, "pint") == 0)
					{
						operations[co].f(&stack, line);
						break;
					}
					co++;
				}
				co = 0;
			}
			else if (strcmp(tokens[t], "swap") == 0)
			{
				while (operations[co].opcode != NULL)
				{
					if (strcmp(operations[co].opcode, "swap") == 0)
					{
						operations[co].f(&stack, line);
						break;
					}
					co++;
				}
				co = 0;
			}
			else if (strcmp(tokens[t], "add") == 0)
			{
				while (operations[co].opcode != NULL)
				{
					if (strcmp(operations[co].opcode, "add") == 0)
					{
						operations[co].f(&stack, line);
						break;
					}
					co++;
				}
				co = 0;
			}
				else if (strcmp(tokens[t], "sub") == 0)
			{
				while (operations[co].opcode != NULL)
				{
					if (strcmp(operations[co].opcode, "sub") == 0)
					{
						operations[co].f(&stack, line);
						break;
					}
					co++;
				}
				co = 0;
			}
				else if (strcmp(tokens[t], "div") == 0)
			{
				while (operations[co].opcode != NULL)
				{
					if (strcmp(operations[co].opcode, "div") == 0)
					{
						operations[co].f(&stack, line);
						break;
					}
					co++;
				}
				co = 0;
			}
			else if (strcmp(tokens[t], "mul") == 0)
			{
				while (operations[co].opcode != NULL)
				{
					if (strcmp(operations[co].opcode, "mul") == 0)
					{
						operations[co].f(&stack, line);
						break;
					}
					co++;
				}
				co = 0;
			}
			else if (strcmp(tokens[t], "mod") == 0)
			{
				while (operations[co].opcode != NULL)
				{
					if (strcmp(operations[co].opcode, "mod") == 0)
					{
						operations[co].f(&stack, line);
						break;
					}
					co++;
				}
				co = 0;
			}
			else if (strcmp(tokens[t], "pchar") == 0)
			{
				while (operations[co].opcode != NULL)
				{
					if (strcmp(operations[co].opcode, "pchar") == 0)
					{
						operations[co].f(&stack, line);
						break;
					}
					co++;
				}
				co = 0;
			}
			t++;
		}
		free(tokens);
		line++;
	}
	fclose(fd);
	for (j = 0; j < line - 1; j++)
	{
		free(strings[j]);
	}
	free(strings);
	free_stack(&stack);
	return (0);
}
