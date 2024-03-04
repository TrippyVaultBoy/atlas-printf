#include <stdio.h>
#include "main.h"


int _printf(const char *format, ...)
{
	int len;

	va_list args;

	int bookmark;

	va_start(args, format);

	len = _strlen(format);

	bookmark = 0;

loop:
	for (; bookmark != '%' && bookmark < len; format++)
	{
		_putchar(format[bookmark]);


		if (format[bookmark++] == 'c')
		{
			printf_char(va_arg);
		}
		else if (format[bookmark++] == 's')
		{
			printf_str(va_arg);
		}
		else if (format[bookmark++] == '%')
                {
                        printf_per(void);
                }
		else if (format[bookmark++] == 'd')
                {
                        printf_int(va_arg);
                }
		else if (format[bookmark++] == 'i')
                {
                        printf_dec(va_arg);
                }
		goto loop;
	}
	return (len);
}


/**
 * _printf - prints output according to format
 * @format: string being passed
 * Return: char to be printed
 */
//int _printf(const char *format, ...)
//{
//	va_list list;
//	int a = 0;
//
//	fmt_t ops[] = {
//		{"%c", _char},
//		{"%s", _str},
//		{"%d", _dec},
//		{"%i", _int},
//		{"%%", _per},
//		{NULL, NULL}
//	};
//
//	if (format == NULL)
//		return (-1);
//	va_start(list, format);
//	a = print_op(format, ops, list);
//	va_end(list);
//	return (a);
//}
