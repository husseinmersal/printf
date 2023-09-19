#include "main.h"

/**
 * print_HEXA - function that Prints number in upper hexadecimal notation
 * @types: Arguments list
 * @buffer: Buffer array to handle print
 * @flags: Gives the active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Specifier size
 * Return: The printed string
 */
int print_HEXA(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}
