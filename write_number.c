#include "main.h"

/**
 * write_number - Function that prints a string
 * @is_negative: Arguments list
 * @ind: char types.
 * @buffer: Buffer array to handle print
 * @flags:  Gives active flags
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int write_number(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & ZERO_FLAG) && !(flags & MINUS_FLAG))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & PLUS_FLAG)
		extra_ch = '+';
	else if (flags & SPACE_FLAG)
		extra_ch = ' ';

	return (write_num(ind, buffer, flags, width, precision,
		length, padd, extra_ch));
}

