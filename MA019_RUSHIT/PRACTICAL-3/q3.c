#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, sum = 0;
    int *arr1, *arr2;

    // Accepting size for first array
    printf("Enter the size of the first array: ");
    scanf("%d", &n);

    // Allocating memory dynamically for first array
    arr1 = (int *)malloc(n * sizeof(int));

    if (arr1 == NULL)
    {
        printf("Memory allocation failed!\n");
        return 0;
    }

    // Accepting values for first array
    printf("Enter the elements of the first array: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
        sum += arr1[i];
    }

    // Accepting size for second array
    printf("Enter the size of the second array: ");
    scanf("%d", &m);

    // Allocating memory dynamically for second array
    arr2 = (int *)realloc(arr1, m * sizeof(int));
    
    if (arr2 == NULL)
    {
        printf("Memory allocation failed!\n");
        return 0;
    }

    // Accepting values for second array
    printf("Enter the elements of the second array: \n");
    for (int i = n; i < m; i++)
    {
        scanf("%d", &arr2[i]);
        sum += arr2[i];
    }

    // Printing sum of all elements
    printf("Sum of all elements: %d\n", sum);

    // Deallocating memory
    free(arr2);

    return 0;
}
