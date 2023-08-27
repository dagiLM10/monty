#include "monty.h"

/**
 * set_op_tok_error - Sets op_toks last element to an error code.
 * @error_code: Stores strings in op_toks integers.
 */
void set_op_tok_error(int error_code)
{
	int toks_len = 0, n = 0;
	char *exit_str = NULL;
	char **new_toks = NULL;

	toks_len = token_arr_le();
	new_toks = malloc(sizeof(char *) * (toks_len + 2));
	if (!op_toks)
	{
		malloc_error();
		return;
	}
	while (n < toks_len)
	{
		new_toks[n] = op_toks[n];
		n++;
	}
	exit_str = get_int(error_code);
	if (!exit_str)
	{
		free(new_toks);
		malloc_error();
		return;
	}
	new_toks[n++] = exit_str;
	new_toks[n] = NULL;
	free(op_toks);
	op_toks = new_toks;
}
