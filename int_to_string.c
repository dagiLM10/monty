#include <stdlib.h>

char *get_int(int num);
unsigned int _abs(int);
int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base,
			char *buff, int buff_size);

/**
 * get_int - gets a character pointer to new string containing int
 * @num: number to convert the string
 *
 * Return: pointer to newly created string. NULL if it fails.
 */
char *get_int(int num)
{
	unsigned int temp;
	int length = 0;
	long num_l = 0;
	char *ret;

	temp = _abs(num);
	length = get_numbase_len(temp, 10);

	if (num < 0 || num_l < 0)
		length++; /* negative sign */
	ret = malloc(length + 1); /* create new string */
	if (!ret)
		return (NULL);

	fill_numbase_buff(temp, 10, ret, length);
	if (num < 0 || num_l < 0)
		ret[0] = '-';

	return (ret);
}

/**
 * _abs - gets the absolute value of an integer
 * @i: integer gets absolute value.
 *
 * Return: unsigned integer abs representation of 1
 */
unsigned int _abs(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}

/**
 * get_numbase_len - gets length of buffer needed for an unsigned int
 * @num: number to get length needed
 * @base: base representation used by buffer
 *
 * Return: integer containing length of buffer needed
 */
int get_numbase_len(unsigned int num, unsigned int base)
{
	int l = 1;

	while (num > base - 1)
	{
		l++;
		num /= base;
	}
	return (l);
}

/**
 * fill_numbers_buff - fills correct numbers to 36
 * @num: To convert to string base
 * @base: base in conversion, only upto base 36
 * @buff: buffer to fill by conversion
 * @buff_size: size of buffer in bytes
 *
 * Return: always void
 */
void fill_numbase_buff(unsigned int num, unsigned int base,
			char *buff, int buff_size)
{
	int r, i = buff_size - 1;

	buff[buff_size] = '\0';
	while (i >= 0)
	{
		r = num % base;
		if (r > 9) /* return lowercase ascil val representation */
			buff[i] = r + 87; /* 10 is a, 11 = b, */
		else
			buff[i] = r + '0';
		num /= base;
		i--;
	}
}
