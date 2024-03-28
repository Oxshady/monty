#include "monty.h"
void _pint(stack_t **top, unsigned int num)
{
	(void)num;
	if ((*top) != NULL)
		printf("%i\n",(*top)->n);
}