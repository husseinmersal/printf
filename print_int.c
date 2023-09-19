#include "main.h"

/**
 * print_int - function that Print integer
 * @types: Argument list
 * @buffer: Buffer array to handle print
 * @flags:  Gives the active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: the printed number of characters
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int num = va_arg(types, long int);
	unsigned long int number;

	num = convert_size_number(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	number = (unsigned long int)num;

	if (num < 0)
	{
		number = (unsigned long int)((-1) * num);
		is_negative = 1;
	}

	while (number > 0)
	{
		buffer[i--] = (number % 10) + '0';
		number /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}
