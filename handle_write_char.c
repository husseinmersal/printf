#include "main.h"

/**
 * handle_write_char - function that prints a string
 * @c: char types.
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags.
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size)
{
	int counter = 0;
	char start_pad = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & ZERO_FLAG)
		start_pad = '0';

	buffer[counter++] = c;
	buffer[counter] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (counter = 0; counter < width - 1; counter++)
			buffer[BUFF_SIZE - counter - 2] = start_pad;

		if (flags & MINUS_FLAG)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - counter - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - counter - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

