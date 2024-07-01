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
		_putchar('\n');
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

	for (; *p != '\0'; p++) {
		if (*p == '%') {
			p++;
			if (*p == 'c') {
				int c = va_arg(args, int);
				_putchar(c);
				count++;
				break;
			}
			else if (*p == 's') {
				char *s = va_arg(args, char *);
				count += _puts(s);
				break;
			}
			else if (*p == '%') {
				_putchar('%');
				count++;
			}
			else
			{
				_putchar(*p);
				count++;
			}
		}
	}

	va_end(args);
	return count;
}