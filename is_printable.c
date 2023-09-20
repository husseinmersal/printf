#include "main.h"

/**
 * is_printable - Evaluates if a char is printable
 * @c: Char to be evaluated.
 *
 * Return: 1 if charac is printable, 0 otherwise
 */
int is_printable(char charac)
{
	if (charac >= 32 && charac < 127)
		return (1);

	return (0);
}

