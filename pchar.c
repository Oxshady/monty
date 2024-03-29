#include "monty.h"
/**
 * _pchar - prints the char at the top of the stack
 * @top: pointer to pointer to the top of stack
 * @num: line number
*/
void _pchar(stack_t **top, unsigned int num)
{
	if ((*top) != NULL)
	{
		if ((*top)->n >= 0 && (*top)->n <= 127)
		{
			putchar((*top)->n);
			putchar('\n');
		}
		else
		{
			fprintf(stderr, "L%u: can't pchar, value out of range\n", num);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, " L%u: can't pchar, stack empty\n", num);
		exit(EXIT_FAILURE);
	}
}