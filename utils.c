#include "main.h"

/**
 * is_printable - evaluates if a char is printable
 * @c: char to be evaluated
 * Return: 1 if true else 0
 */

int is_printable(char c)
{
	if (c >= 32 && c < 127)
	return (1);

	return (0);
}

/**
 * append_hexa_code - Append ascii in hexadecimak code to buffer
 * @buffer: array of chars
 * @i: index at which to start appending
 * @ascii_code: ASCII code
 * Return: 3
 */

int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
	ascii_code = ascii_code * -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';
	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - checks if a char is digit
 * @c: char to be checked
 * Return: 1 if true otherwise 0
 */

int is_digit(char c)
{
	if (c > '0' && c <= '9')
	return (1);

	return (0);
}

/**
 * convert_size_number - casts a number to the specified size
 * @num: number to be casted
 * @size: indicator
 * Return: casted value of number
 */

long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
	return (num);
	else if (size ==  S_SHORT)
	return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - casts a number to the specified size
 * @num: number to be casted
 * @size: indicator
 * Return: casted value of num
 */

long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
	return (num);
	else if (size == S_SHORT)
	return ((unsigned short)num);

	return ((unsigned int)num);
}
