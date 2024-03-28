#include "monty.h"

/**
 * add - Add the top two elements of the stack
 * @top: Pointer to pointer to the top of the stack
 * @num: Line number
 */
void _add(stack_t **top, unsigned int num)
{
	int sum = 0;
	stack_t *temp = NULL;

	if (*top != NULL && (*top)->next != NULL)
	{
		sum = (*top)->n + (*top)->next->n;

		(*top)->n = sum;

		temp = (*top)->next;
		(*top)->next = (*top)->next->next;
		if ((*top)->next != NULL)
			(*top)->next->prev = *top;
		free(temp);
	}
	else
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", num);
		exit(EXIT_FAILURE);
	}
}
