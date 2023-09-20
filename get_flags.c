#include "main.h"

/**
 * get_flags - function that give the active flags
 * @format: Format argument
 * @i: parameter
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	int j, current_i;
	int flags = 0;
	const char flag_chars[] = {'-', '+', '0', '#', ' ', '\0'};
	const int flag_array[] = {MINUS_FLAG, PLUS_FLAG, ZERO_FLAG, HASHTAG_FLAG,
		SPACE_FLAG, 0};

	for (current_i = *i + 1; format[current_i] != '\0'; current_i++)
	{
		for (j = 0; flag_chars[j] != '\0'; j++)
			if (format[current_i] == flag_chars[j])
			{
				flags |= flag_array[j];
				break;
			}

		if (flag_chars[j] == 0)
			break;
	}

	*i = current_i - 1;

	return (flags);
}
