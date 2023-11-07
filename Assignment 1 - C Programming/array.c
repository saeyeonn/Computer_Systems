#include <stdio.h>

int main() {
    printf("\n\n\t\tStudytonight - Best place to learn\n\n\n");
    int arr[100], position, c, n, value;

    printf("\n\nEnter number of elements in array: ");
    scanf("%d", &n);

    printf("\n\nEnter %d elements\n", n);
    for (c = 0; c < n; c++)
        scanf("%d", &arr[c]);

    printf("\n\nEnter the location where you want to insert new element:  ");
    scanf("%d", &position);

    printf("\n\nEnter the value to insert: ");
    scanf("%d", &value);

    for (c = n - 1; position <= c; c--)
        arr[c + 1] = arr[c];

    arr[position - 1] = value;

    printf("\n\nResultant array is: ");

    for (c = 0; c <= n; c++)
        printf("%d ", arr[c]);
        
    printf("\n\n\t\t\tCoding is Fun !\n\n\n");
    return 0;
}