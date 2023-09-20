#include "main.h"
/**
 * handle_print - Function that Prints an argument according to its type
 * @format: Format argument
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */
int handle_print(const char *format, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknown_len = 0, printed_chars = -1;
	format_t format_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_HEXA}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
<<<<<<< HEAD

	for (counter = 0; format_types[counter].format != '\0'; counter++)
		if (format[*ind] == format_types[counter].format)
			return (format_types[counter].fn(list, buffer, flags, width,
				precision, size));
	for ( counter = 0; format_types[counter].format != '\0'; i++)
		if (format[*ind] == format_types[ counter].format)
			return (format_types[ counter].fn(list, buffer, flags, width, precision, size));

=======
	for (i = 0; format_types[i].format != '\0'; i++)
		if (format[*ind] == format_types[i].format)
			return (format_types[i].fn(list, buffer, flags, width, precision, size));
>>>>>>> eef4a1e4a2926f2fbcc9f005c7e0f6ed4d8fca7c

	if (format_types[i].format == '\0')
	{
		if (format[*ind] == '\0')
			return (-1);
		unknown_len += write(1, "%%", 1);
		if (format[*ind - 1] == ' ')
			unknown_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (format[*ind] != ' ' && format[*ind] != '%')
				--(*ind);
			if (format[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknown_len += write(1, &format[*ind], 1);
		return (unknown_len);
	}
	return (printed_chars);
}
