/* main.c */
#include <stdio.h>

extern int a, c;
static int b = 2;
void foo(void);

int main() {
    int c = 4;
    foo();
    printf("a=%d b=%d c=%d\n", a, b, c);
    return 0;
}