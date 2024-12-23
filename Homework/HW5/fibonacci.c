#include <stdio.h>

unsigned long long fibonacci(unsigned long long n) 
{
    if (n <= 1) return n;
    
    unsigned long long prev = 0, curr = 1, next;
    for (unsigned long long i = 2; i <= n; i++) 
    {
        next = prev + curr;
        prev = curr;
        curr = next;
    }
    return curr;
}

int main() {
    unsigned long long i;
    unsigned long long n = 90;
    
    printf("Fibonacci of %lld: \n", n);
    
    for(i = 0; i<n; i++) 
    {
        printf("%lld ", fibonacci(i));
    }
    printf("\n");
    return 0;
}