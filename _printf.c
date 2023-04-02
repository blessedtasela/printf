#include "main.h"

void print_buffer(char buffer[], int *buffer_in);

/**
 * _printf - function to print inputs to standard output
 * @format: format indentifier or format input
 * @...: other formats
 * Return: 0 on success
 */

int _printf(const char *format, ...)
{
	int i, printed = 0, printed_char = 0, buffer_in = 0;
	int flags, width, precision, size;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
		buffer[buffer_in++] = format[i];
		if (buffer_in == BUFF_SIZE)
		print_buffer(buffer, &buffer_in);
		printed_char++;
		}
		else
		{
		print_buffer(buffer, &buffer_in);
		flags = get_flags(format, &i);
		width = get_width(format, &i, list);
		precision = get_precision(format, &i, list);
		size = get_size(format, &i);
		++i;
		printed = handle_print(format, &i, list, buffer,
		 flags, width, precision, size);
		if (printed == -1)
		return (-1);
		printed_char = printed_char + printed;
		}
	}

	print_buffer(buffer, &buffer_in);
	va_end(list);

	return (printed_char);
}

/**
 * print_buffer - prints the contents of the buffer if not null
 * @buffer: array to be printed
 * @buff_ind: index at which add the next character, also represent the length
 */

void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}

