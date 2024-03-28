#include "monty.h"

/**
 * _sub - sub the top two elements of the stack
 * @top: Pointer to pointer to the top of the stack
 * @num: Line number
 */
void _sub(stack_t **top, unsigned int num)
{
	int sub = 0;
	stack_t *temp = NULL;

	if (*top != NULL && (*top)->next != NULL)
	{
		sub = (*top)->n - (*top)->next->n;

		(*top)->n = sub;

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
/**
 * _div - division of the top two elements of the stack
 * @top: Pointer to pointer to the top of the stack
 * @num: Line number
 */
void _div(stack_t **top, unsigned int num)
{
	int div = 0;
	stack_t *temp = NULL;

	if (*top != NULL && (*top)->next != NULL)
	{
		div = (*top)->n / (*top)->next->n;

		(*top)->n = div;

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
/**
 * _mod - modules of the top two elements of the stack
 * @top: Pointer to pointer to the top of the stack
 * @num: Line number
 */
void _mod(stack_t **top, unsigned int num)
{
	int mod = 0;
	stack_t *temp = NULL;

	if (*top != NULL && (*top)->next != NULL)
	{
		mod = (*top)->n % (*top)->next->n;

		(*top)->n = mod;

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
