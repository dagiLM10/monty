#include "monty.h"
#include <string.h>

void free_tokens(void);
unsigned int token_arr_len(void);
int is_empty_line(char *line, char *delims);
void (*get_op_func(char *opcode))(stack_t**, unsigned int);
int run_monty(FILE *script_fd);

/**
 * free_tokens - Frees the global op_toks array of strings.
 */
void free_tokens(void)
{
	size_t n = 0;

	if (op_toks == NULL)
		return;

	for (n = 0; op_toks[n]; n++)
		free(op_toks[n]);

	free(op_toks);
}

/**
 * token_arr_len - Gets current op_toks's length.
 *
 * Return: current op_toks's length
 */
unsigned int token_arr_len(void)
{
	unsigned int toks_len = 0;

	while (op_toks[toks_len])
		toks_len++;
	return (toks_len);
}

/**
 * is_empty_line - Checks if a line read from getline only contains delimiters.
 * @line: the line's pointer
 * @delims: delimiter characters string
 *
 * Return: if it cotains delomiters - 1.
 *		other wise - 0.
 */
int is_empty_line(char *line, char *delims)
{
	int a, b;

	for (a = 0; line[a]; a++)
	{
		for (b = 0; delims[b]; b++)
		{
			if (line[a] == delims[b])
				break;
		}
		if (delims[b] == '\0')
			return (0);
	}

	return (1);
}

/**
 * get_op_func - Matches an opcode with its corresponding function.
 * @opcode: The opcode to match.
