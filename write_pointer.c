#include "main.h"

/**
 * write_pointer - Write a memory address
 * @buffer: Arrays of chars
 * @ind: Index at which the number starts in the buffer
 * @length: Length of number
 * @width: Width specifier
 * @flags: Flags specifier
 * @padd: Char representing the padding
 * @extra_char: Char representing extra char
 * @padd_start: Index at which padding should start
 *
 * Return: The printed number of characters.
 */
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char pading, char extra_char, int pad_start)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buffer[i] = pading;
		buffer[i] = '\0';
		if (flags & MINUS_FLAG && pading == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_char)
				buffer[--ind] = extra_char;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & MINUS_FLAG) && pading == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_char)
				buffer[--ind] = extra_char;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & MINUS_FLAG) && pading == '0')
		{
			if (extra_char)
				buffer[--pad_start] = extra_char;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[pad_start], i - pad_start) +
				write(1, &buffer[ind], length - (1 - pad_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_char)
		buffer[--ind] = extra_char;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}

