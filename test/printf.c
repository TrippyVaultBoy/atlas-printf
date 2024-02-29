#include <stdio.h>
#include <stdlib>
#include <stdarg>

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
