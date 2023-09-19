#include "main.h"

/**
 * print_char - Function that Prints a char
 * @types: Arguments list
 * @buffer: Buffer array
 * @flags:  Gives the active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Specifier size
 * Return: the printed characters
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
