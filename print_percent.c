#include "main.h"

/**
 * print_percent - Function that prints a percent sign
 * @types: Arguments list
 * @buffer: Buffer array to handle print
 * @flags: Gives active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: The printed number of characters
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}
