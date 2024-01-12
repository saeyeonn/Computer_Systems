/*
Q1. Why the compiled executable file from original source code takes so long time to produce output?

The provided fibonacci code calculates the sequence using a recursive approach. 
The function recursively calls itself to calculate fibonacci numbers 
without memoization or dynamic programming.
The recursive fibonacci calculation leads to a great big amount of redundant computations. 
This exponential growth in redundant calculations leads to a high time complexity.
*/

#include <stdio.h>

// Q2. Update source code to get the correct result.

unsigned long long fibonacci(unsigned long long n) {
   unsigned long long n1 = 0, n2 = 1, temp;

   if (n == 0 || n == 1) return n;
   for (size_t i = 0; i < n - 1; i++)
   {
      temp = n2;
      n2 += n1; 
      n1 = temp;
   }
   return n2;
}

int main() {
   unsigned long long i;
   unsigned long long n = 90;
	
   printf("Fibonacci of %lld: \n" , n);
	
   for(i = 0;i<n;i++) {
      printf("%lld ",fibonacci(i));            
   }
   printf("\n"); 
   return 0; 
}
