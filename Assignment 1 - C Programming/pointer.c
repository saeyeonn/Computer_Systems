#include <stdio.h>

const int MAX = 4;
int main() 
{
    printf("\n\n\t\tStudytonight - Best place to learn\n\n\n");
    int var[] = {100, 200, 300, 21102054};
    int *ptr = var;

    for (int i = 0; i < MAX; i++)
    {
        printf("\n\n\nAddress of var[%d] = %x", i, ptr);
        printf("\nvalue of var[%d] = %d", i, *(ptr++));
    }
    printf("\n\n\t\t\tCoding is Fun !\n\n\n");
    return 0;
}