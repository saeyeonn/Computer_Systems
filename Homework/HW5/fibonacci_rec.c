#include <stdio.h>
unsigned long long fibonacci(unsigned long long n) 
{   
    if (n == 0)
    {
        return 0;
    } 
    else if (n == 1) 
    {
        return 1;
    } 
    else 
    {
        return (fibonacci(n-1) + fibonacci(n-2)); 
    }
}

int main() 
{
    unsigned long long i;
    unsigned long long n = 90;
    
    printf("Fibonacci of %lld: \n" , n);
    for(i = 0; i < n;i++) 
    {
        printf("%lld ",fibonacci(i)); 
    }
    printf("\n");
    return 0; 
}