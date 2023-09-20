#include "main.h"

/**
 * is_digit - Verifies if a char is a digit
 * @charac: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char charac)
{
	if (charac >= '0' && charac <= '9')
		return (1);

	return (0);
}

