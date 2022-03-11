#include <stdio.h>

/**
 * main - print alphabet in lower and uppercase
 *
 *
 * Return: (0) Success
 */
int main() {
    char c;
    for (c = 'a'; c <= 'z'; ++c) {
        putchar(c);
}
for (c = 'A'; c <= 'Z'; ++c) {
    putchar(c);
}
return (0);
}
