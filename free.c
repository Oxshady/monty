#include "monty.h"
/**
 * free_stack - function that free the stack
 * @top: pointer to pointer to stack
*/
void free_stack(stack_t **top)
{
	stack_t *current = *top;
	stack_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*top = NULL;
}
