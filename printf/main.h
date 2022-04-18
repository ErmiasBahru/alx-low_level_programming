#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct cformat
{
char *print;
int (*p)();
} cf_t;

int _printf(const char *format, ...);
int _putchar(char c);
int pc(va_list arg);
int ps(va_list arg);
int pd(va_list arg);
int pi(va_list arg);

#endif
