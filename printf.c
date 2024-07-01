#include "main.h"

/* compile with: gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format *.c */

int _putchar(char c) {
	return write(1, &c, 1);
}

int _puts(const char *str) {
	int count;

	count = 0;

	while (*str) {
		_putchar(*str++);
		count++;
	}
	return count;
}

int _printf(const char *format, ...) {
	int count;
	const char *p = format;
	
	va_list args;
    va_start(args, format);

	count = 0;

	if (format == NULL) {
		return count;
	}

	for (; *p != '\0'; p++) {
		if (*p == '%') {
            p++;
			if (*p == '\0') {
                va_end(args);
                return count;
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
					if (s == NULL) {
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
	return count;
}