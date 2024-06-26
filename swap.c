#include "monty.h"
/**
 * _swap - function that swaps the top two elements of the stack
 * @top: pointer to pointer to the top of the stack
 * @num: line number
 */
void _swap(stack_t **top, unsigned int num)
{
	stack_t *n1 = NULL;
	stack_t *n2 = NULL;

	if (*top != NULL && (*top)->next != NULL)
	{
		n1 = *top;
		n2 = (*top)->next;

		n1->next = n2->next;
		n2->prev = NULL;
		n1->prev = n2;
		n2->next = n1;
		*top = n2;
		if (n1->next != NULL)
		{
			n1->next->prev = n1;
		}
	}
	else
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", num);
		exit(EXIT_FAILURE);
	}
}
