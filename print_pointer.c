#include "main.h"

/**
 * print_pointer - function that prints the value of a pointer variable
 * @types: Arguments list
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: The printed number of characters
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_char = 0, pading = ' ';
	int ind = BUFF_SIZE - 2, length = 2, pading_start = 1;
	unsigned long number_address;
	char array[] = "0123456789abcdef";
	void *address = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (address == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	number_address = (unsigned long)address;

	while (number_address > 0)
	{
		buffer[ind--] = array[number_address % 16];
		number_address /= 16;
		length++;
	}

	if ((flags & ZERO_FLAG) && !(flags & MINUS_FLAG))
		pading = '0';
	if (flags & PLUS_FLAG)
		extra_char = '+', length++;
	else if (flags & SPACE_FLAG)
		extra_char = ' ', length++;

	ind++;

	return (write_pointer(buffer, ind, length,
		width, flags, pading, extra_char, pading_start));
}
