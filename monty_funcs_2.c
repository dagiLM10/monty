#include "monty.h"

void monty_add(stack_t **stack, unsigned int line_number);
void monty_sub(stack_t **stack, unsigned int line_number);
void monty_div(stack_t **stack, unsigned int line_number);
void monty_mul(stack_t **stack, unsigned int line_number);
void monty_mod(stack_t **stack, unsigned int line_number);

/**
 * monty_add - Adds the two higher values of a stack_t linked list.
 * @stack: pointer of top node of a stack_t linked list.
 * @line_number: working line nuber of monty bytecodes file.
 *
 * Description: result is stored to the second value node
 * 		on top and top value is removed.
 */
void monty_add(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_sub - Subtracts second value on the top of
 *		a stack_t linked list
 * @stack: top mode node pointer of a stack_t linked list.
 * @line_number: Monty bytecodes file of a current working line number.
 *
 * Description: Result is stored in the second value node
 *		on top and the top value is removed.
 */
void monty_sub(stack_t **stack, unsigned int line_number)
{
	if ((*stack->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_div - Divides second value from the top of
 *		a stack_t linked list.
 * @stack: Top mode node of a stack_t linked list pointer.
 * @linked_number: Monty bytecodes file of a current working line number.
 *
 * Description: Result is stoed in the second value node
 *		on top and the top value is removed.
 */
void monty_div(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "div"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(div_error(line_number));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_mul - Multipies second value on top of 
 *		a stack_t linked list.
 * @stack:stack_t linked list of a top mode node pointer.
 * @line_number: Monty bytecodes file of current working line number.
 *
 * Description: Result is stored in second value top of the node
 *		and top value is removed.
 */
void monty_mul(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_mod - Computes second value on top of
 *		a stack_t linked list.
 * @stack: stack_t linked list of a top mode node pointer.
 * @line_number: Monty bytecodes file of a current working line number.
 *
 * Descriptio: Result is stored in second value on top of the node
 *		and top value is removed.
 */
void monty_mod(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "mod"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(div_error(line_number));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	monty_pop(stack, line_number);
}
