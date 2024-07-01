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

void reverse(char *str, int length)
{
	int first = 0;
	int last = length - 1;

	while (first < last)
	{
		char temp = str[first];
		str[first] = str[last];
		str[last] = temp;
		first++;
		last--;
	}
}

char* _itoa(int n, char *str)
{
	int i;
	int j;
	int is_negative;
	char min_int[] = "-2147483648";

	i = 0;
	is_negative = 0;

	if (n == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return str;
	}

	if (n < 0)
	{
		is_negative = 1;
		n = -n;
	}

	if (n == -2147483648)
    {
		for (j = 0; min_int[j] != '\0'; j++)
		{
			str[i] = min_int[j];
			i++;
		}
		str[i] = '\0';
		return str;
	}

	while (n != 0)
	{
		int remainder = n % 10;
		str[i++] = remainder + '0';
		n /= 10;
	}

	if (is_negative)
	{
		str[i++] = '-';
	}

	str[i] = '\0';

	reverse(str, i);

	return (str);
}

int _printf(const char *format, ...)
{
	int count;
	const char *p = format;
	char str[20];

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
                    _itoa(d, str);
					count += _puts(str);
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