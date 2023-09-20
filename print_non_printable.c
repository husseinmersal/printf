#include "main.h"

/**
 * print_non_printable - function Prints ascii codes of non printable chars
 * @types: Arguments list
 * @buffer: Buffer array to handle print
 * @flags:  Gives active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: the printed number of characters
 */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += append_hexa_code(str[i], buffer, i + offset);

		i++;
	}

	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
<<<<<<< HEAD
=======
}
>>>>>>> eef4a1e4a2926f2fbcc9f005c7e0f6ed4d8fca7c
