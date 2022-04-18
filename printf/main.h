#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);
int op_c(va_list al);
int op_s(va_list al);
int op_d(va_list al);
int op_u(va_list al);
int op_o(va_list al);
int op_x(va_list al);
int op_X(va_list al);
int op_p(va_list al);
int op_r(va_list al);
int op_percent(va_list al);
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
