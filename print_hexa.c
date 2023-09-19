#include "main.h"

/**
 * print_hexa - function that Prints a hexadecimal number in lower or upper
 * @types: Arguments list
 * @array: Array of values
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * @size: Size specification
 * Return: The printed number
 */
int print_hexa(va_list types, char array[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int number = va_arg(types, unsigned long int);
	unsigned long int initial_number = number;

	UNUSED(width);

	number = convert_size_unsigned(number, size);

	if (number == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[i--] = array[number % 16];
		number /= 16;
	}

	if (flags & HASHTAG_FLAG && initial_number != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
