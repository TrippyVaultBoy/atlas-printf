#include "main.h"

/** compile with: gcc -Wall -Wextra -Werror
-pedantic -std=gnu89 -Wno-format *.c **/

int _putchar(char c)
{
	return (write(1, &c, 1));
}

int _puts(const char *str)
{
	int count;

	count = 0;

	while (*str) {
		_putchar(*str++);
		count++;
	}
	return (count);
}

int print_integer(int n)
{
	int count;
	int negative;
	int i;
	int digits[10];

	count = 0;
	negative = 0;
	i = 0;

	if (n < 0)
	{
		negative = 1;
	}

	do
	{
		digits[i++] = n % 10;
		n /= 10;
	} while (n != 0);

	if (negative == 1)
	{
		_putchar('-');
		count++;
	}

	while (i > 0)
	{
		_putchar(digits[--i] + '0');
		count++;
	}

	return (count);
}

int _printf(const char *format, ...)
{
	int count;
	const char *p = format;

	va_list args;
	va_start(args, format);

	count = 0;

	if (format == NULL)
		return (-1);

	for (; *p != '\0'; p++)
	{
		if (*p == '%')
		{
            p++;
			if (*p == '\0')
			{
                va_end(args);
                return (-1);
            }
            switch (*p) {
                case 'c': {
                    int c = va_arg(args, int);
                    _putchar(c);
                    count++;
                    break;
				}
                case 's': {
					char *s = va_arg(args, char *);
					if (s == NULL)
					{
						_puts("(null)");
						count += 6;
						break;
					}
					else
					{
                    	count += _puts(s);
                    	break;
					}
                }
				case 'd': {
                    int d = va_arg(args, int);
                    count =+ print_integer(d);
                    break;
                }
				case 'i': {
                    int i = va_arg(args, int);
                    _putchar(i);
                    count++;
                    break;
                }
                case '%': {
                    _putchar(*p);
                    count++;
                    break;
                }
                default: {
                    _putchar('%');
                    _putchar(*p);
                    count += 2;
                    break;
                }
            }
        }
		else
		{
			_putchar(*p);
			count++;
		}
	}

	va_end(args);
	return (count);
}