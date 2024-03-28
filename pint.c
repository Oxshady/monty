#include "monty.h"
/**
 * _pint - function that print the top of the stack
 * @top: pointer to pointer to the top of the stack
 * @num: line number
*/
void _pint(stack_t **top, unsigned int num)
{
	(void)num;
	if ((*top) != NULL)
		printf("%i\n", (*top)->n);
}
