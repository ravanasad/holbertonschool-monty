#include "monty.h"
/**
 * f_add - adds the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: the line number in the file
 * Return: void
 */
void f_add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp->next->n = tmp->next->n + tmp->n;
	*stack = tmp->next;
	free(tmp);
}
