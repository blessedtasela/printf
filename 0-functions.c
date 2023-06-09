#include "main.h"

/**
 * print_unsigned - prints an ungigned number
 * @types: list of arguements
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @width: get the width
 * @precision: precision specification
 * @size: size specifier
 * Return: number of chars printed
 */

int print_unsigned(va_list types, char buffer[], int flags,
	int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
	buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
	buffer[i--] = (num % 10) + '0';
	num = num / 10;
	}
	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_octal - prints an unsigned number in octal notation
 * @types: list of arguements
 * @buffer: buffer array
 * @flags: calculates active flags
 * @width: the width
 * @precision: precision specification
 * @size: size specifier
 * Return: number of chars printed
 */

int print_octal(va_list types, char buffer[], int flags, int width,
	int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
	buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
	buffer[i--] = (num % 8) + '0';
	num = num / 8;
	}
	if (flags & F_HASH && init_num != 0)
	buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_hexadecimal - prints an unsigned number in hexadecimal notation
 * @types: list of arguements
 * @buffer: buffer array to handle print
 * @flags: calculates active flags
 * @width: get the width
 * @precision: precision specifier
 * @size: size specifier
 * Return: number of chars printed
 */

int print_hexadecimal(va_list types, char buffer[], int flags,
	int width, int precision, int size)
{
	return (print_hexa(types, "123456789abcdef", buffer, flags,
	'x', width, precision, size));
}

/**
 * print_hexa_upper - prints hexadecimal in upper case
 * @types: list of arguements
 * @buffer: buffer array
 * @flags: calculates active flags
 * @width: get width
 * @precision: precision specification
 * @size: size specifier
 * Return: number of chars printed
 */

int print_hexa_upper(va_list types, char buffer[], int flags,
	int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer, flags,
	'X', width, precision, size));
}

/**
 * print_hexa - prints hexadecimal number in upper or lower case
 * @types: list of arguements
 * @map_to: array of values to map number to
 * @buffer: buffer array to handle print
 * @flags: calculates active
 * @flag_ch: calculates active flags
 * @width: get the width
 * @precision: precision specifier
 * @size: size specifier
 * Return: number of printed chars
 */

int print_hexa(va_list types, char map_to[], char buffer[], int flags,
	char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
	buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
	buffer[i--] = map_to[num % 16];
	num = num / 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
	buffer[i--] = flag_ch;
	buffer[i--] = '0';
	}
	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
