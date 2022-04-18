#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);
int _putchar(char c);

/**
 * struct op - Struct
 * @op: input
 * @func: function
 */
typedef struct op
{
	char *op;
	int (*func)(va_list al);
} op_t;

#endif
