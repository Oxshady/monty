#include "monty.h"
/**
 * _rotl -  rotates the stack to the top
 * @top: pointer to pointer to the top of the stack
 * @num: line number
*/
void _rotl(stack_t **top, unsigned int num)
{
	stack_t *tmp = NULL;
	(void)num;

	if (*top != NULL && (*top)->next != NULL)
	{
		tmp = *top;
		*top = (*top)->next;
		(*top)->prev = NULL;

		stack_t *last = *top;
		while (last->next != NULL)
		{
			last = last->next;
		}

		last->next = tmp;
		tmp->prev = last;
		tmp->next = NULL;
	}
}