#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * main - Entry point
 *
 * Return: 0 on success, error code otherwise
 */
int main(void) {
	int len, len2;
	len = _printf("%c\n", 'S');
	len2 = printf("%c\n", 'S');
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
        printf("%d\n", len);
        printf("%d\n", len2);
		fflush(stdout);
		return (1);
	}
    else
    {
        printf("Lengths are equal.\n");
        printf("%d\n", len);
        printf("%d\n", len2);
        fflush(stdout);
        return (0);
    }
}