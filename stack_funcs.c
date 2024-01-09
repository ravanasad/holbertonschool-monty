#include "monty.h"

/**
 * f_push - pushes an element to the stack
 * @stack: pointer to the stack
 * @value: value
 */
void f_push(stack_t **stack,  int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * f_pall - prints all the values on the stack
 * @stack: pointer to the stack
 * @line_number: the line number in the file
 */
void f_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void)line_number;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
