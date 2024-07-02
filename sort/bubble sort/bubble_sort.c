#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubble(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)  // Optimized the loop to avoid unnecessary comparisons
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");  // Added newline for better output formatting
}

int main()
{
    int arr[] = {9,6,3,8,5,2,7,4,1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("before:\n");
    printArray(arr,n);
    bubble(arr, n);
    printf("The sorted elements are: \n");
    printArray(arr, n);

    return 0;
}
