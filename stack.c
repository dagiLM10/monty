#include "monty.h"
#include <string.h>

void free_stack(stack_t **stack);
int init_stack(stack_t **stack);
int check_mode(stack_t *stack);

/**
 * free_stack - frees a stack_t stack.
 * @stack: A pointer to the top (stack) or
 *	bottom (queue) of a stack_t.
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

/**
 * init_stack - stack_t stack initializer with beginning stack
 *		and ending queue nodes.
 * @stack: stack_t stack unitialized pointer.
 *
 * Return: EXIT_SUCCESS on success otherwise EXIT_SUCCESS.
 */
int init_stack(stack_t **stack)
{
	stack_t *i;

	i = malloc(sizeof(stack_t));
	if (i == NULL)
		return (malloc_error());

	i->n = STACK;
	i->prev = NULL;
	i->next = NULL;

	*stack = i;

	return (EXIT_SUCCESS);
}

/**
 * check_mode - Checks if a stack_t linked list is in stack or queue mode.
 * @stack: A pointer to the top (stack) or bottom (queue)
 *	of a stack_t linked list.
 *
 * Return: If the stack_t is in stack mode - STACK (0).
 *	if the stack_t is queue mode - QUEUE (1).
 *	otherwisw -2.
 */
int check_mode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}
