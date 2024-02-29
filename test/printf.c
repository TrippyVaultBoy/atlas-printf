#include <stdio.h>
#include <stdlib>
#include <stdarg>
#include "main.h"


int _printf(const char *format, ...)
{
	int len;

	va_list args;

	va_start(args, format);

	len = _strlen(format);

loop:
	for (; bookmark != '%' && bookmart < len; format++)
	{
		_putchar(format[bookmark]);


		if (format[bookmark++] == 'c')
		{
			_%c(va_args, char);
		}
		else if (format[bookmark++] == 's')
		{
			_%s(va_args, char);
		}
		else if (format[bookmark]++ == '%')
                {
                        _%%(va_args, char);
                }
		else if (format[bookmark++] == 'd')
                {
                        _%d(va_args, char);
                }
		else if (format[bookmark++] == 'i')
                {
                        _%i(va_args, char);
                }
		goto loop;
		
		return (len);
	}
}


/**
 * _printf - prints output according to format
 * @format: string being passed
 * Return: char to be printed
 */
int _printf(const char *format, ...)
{
	va_list list;
	int a = 0;

	fmt_t ops[] = {
		{"c", ch},
		{"s", str},
		{"d", _dec},
		{"i", _int},
		{"%", _per}
		{NULL, NULL}
	};

	if (format == NULL)
		return (-1);
	va_start(list, format);
	a = print_op(format, ops, list);
	va_end(list);
	return (a);
}
