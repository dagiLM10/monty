#include "monty.h"

void monty_rotl(stack_t **stack, unsiged int line_number);
void monty_rotr(stack_t **stack, unsiged int line_number);
void monty_stack(stack_t **stack, unsiged int line_number);
void monty_queue(stack_t **stack, unsiged int line_number);

/**
 * monty_rotl - Rotates stack_t linked list's top value to the bottom.
 * @stack: stack_t linked list's top mode node pointer.
 * @line_number: Monty bytecodes file of the current working number.
 */
void monty_rotl(stack_t **stack, unsiged int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	top->next->prev = *stack;
	(*stack)->next = top->next;
	bottom->next = top;
	top->next = NULL;
	top->prev = bottom;

	(void)line_number;
}

/**
 * monty_rotr - Rotates stack_t linked list's top value to the bottom.
 * @stack: stack_t linked list's top mode node pointer.
 * @line_number: Monty bytecodes file of the current working number.
 */
void monty_rotr(stack_t **stack, unsiged int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	bottom->prev->next = NULL;
	(*stack)->next = bottom;
	bottom->prev = *stack;
	bottom->next = top;
	top->prev = bottom;

	(void)line_number;
}

/**
 * monty_stack - A stack queue converter.
 * @stack: stack_t linked list's top mode node pointer.
 * @line_number: Monty bytecodes file of the current working number.
 */
void monty_satck(stack_t **stack, unsiged int line_number)
{
	(*stack)->n = STACK;
	(void)line_number;
}

/**
 * monty_queue - A stack queue converter.
 * @stack: stack_t linked list's top mode node pointer.
 * @line_number: Monty bytecodes file of the current working number.
 */
void monty_queue(stack_t **stack, unsiged int line_number)
{
	(*stack)->n = QUEUE;
	(void)line_number;
}
