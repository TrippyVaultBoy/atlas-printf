#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>


int _printf(const char *format, ...);
int _putchar(char c);
int _strlen(const char *s);
int printf_char(va_list val);
int printf_str(va_list val);
int printf_dec(va_list args);
int printf_int(va_list args);
int printf_per(void);
int printf_str(va_list val);
#endif
