#include <stdio.h>

void fibonacci(int run);

void main()
{
    int num = 6;
    
    printf("Enter number of terms: ");
    scanf("%d", &num);
    fibonacci(num);
}

void fibonacci(int num)
{
    int a = 0, b = 1, c, i;
    
    if (num == 1)
        printf("%d", a);
    if (num >= 2)
        printf("%d\t%d", a, b);
    for (i = 3; i <= num; i++)
    {
        c = a + b;
        printf("\t%d", c);
        a = b;
        b = c;
    }
}