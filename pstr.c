#include "monty.h"
/**
 * _pstr - prints the string starting at the top of the stack
 * @top: pointer to pointer to top of stack
 * @num: line number
*/
void _pstr(stack_t **top, unsigned int num)
{
	stack_t *tmp = NULL;

	tmp = (*top);
	if (tmp != NULL)
	{
		if (tmp->n > 0 && tmp->n <= 127)
		{
			putchar(tmp->n);
			tmp = tmp->next;
			while (tmp != NULL)
			{
				if (tmp->n == 0 || (tmp->n < 0 || tmp->n > 127))
					break;
				if (tmp->n > 0 && tmp->n <= 127)
				{
					putchar(tmp->n);
				}
				tmp = tmp->next;
			}
			putchar('\n');		
		}
	}else
		putchar('\n');
}