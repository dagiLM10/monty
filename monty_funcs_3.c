#include "monty.h"

void monty_nop(stack_t **stack, unsigned int line_number);
void monty_pchar(stack_t **stack, unsigned int line_number);
void monty_pstr(stack_t **stack, unsigned int line_number);

/**
 * monty_nop - Dose nothing for the monty opcode 'nop'.
 * @stack: stack_t linked list pointer of top mode node.
 * @line_number: Monty bytecodes file of current working line number.
 */
void monty_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * monty_pchar - Top value node of a stack_t linked list
 *		that prints the character.
 * @stack: Top mode node of a stack_t linked list's pointer.
 * @line_number: Monty bytecodes file of current woring line number.
 */
void monty_pchar(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pchar_error(line_number, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		set_op_tok_error(pchar_error(line_number,
					"value out of range"));
		return;
	}

	printf("%c\n", (*stack)->next->n);
}

/**
 * monty_pstr - stack_t linked list's string contained printer.
 * @stack: Top mode node of a stack_t linked list's pointer.
 * @line_number: Monty bytecodes file of current working line number.
 */
void monty_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <=127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}

	printf("\n");

	(void)line_number;
}
