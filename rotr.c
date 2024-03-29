#include "monty.h"
/**
 * _rotr -  rotates the stack to the bottom
 * @top: pointer to pointer to top of stack
 * @num: line number
*/
void _rotr(stack_t **top, unsigned int num)
{
	stack_t *tmp = NULL;

	(void)num;

	if (*top != NULL && (*top)->next != NULL)
	{
		tmp = *top;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}

		if (tmp->prev != NULL)
		{
			tmp->prev->next = NULL;
			tmp->prev = NULL;
			tmp->next = *top;
			(*top)->prev = tmp;
			*top = tmp;
		}
	}
}
