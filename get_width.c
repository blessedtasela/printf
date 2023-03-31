#include "main.h"

/**
 * get_width - calculates the width for printing
 * @format: formatted string in which to print arguements
 * @i: list of arguements to be printed
 * @list: list of arguements
 * Return: the width
 */

int get_width(const char *format, int *i, va_list list)
{
	int curr_i, width = 0;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
	if (is_digit(format[curr_i]))
	{
	width = width * 10;
	width = width + format[curr_i] - '0';
	}
	else if (format[curr_i] == '*')
	{
	curr_i++;
	width = va_arg(list, int);
	break;
	}
	else
	break;
	}
	*i = curr_i - 1;

	return (width);
}
