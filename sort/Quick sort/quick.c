#include <stdio.h>

// Swap function
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Partition function
int partition(int arr[], int start, int end) {
    int pivot = arr[start];
    int i = start;
    int j = end;

    while (i < j) {
        // Find the first element greater than the pivot (from starting)
        while (arr[i] <= pivot && i <= end - 1) {
            i++;
        }

        // Find the first element smaller than the pivot (from last)
        while (arr[j] > pivot && j >= start) {
            j--;
        }

        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[start], &arr[j]); // Swap pivot with the element at partition index
    return j; // Return partition index
}

// QuickSort function
void quickSort(int arr[], int start, int end) {
    if (start < end) {
        // Call Partition function to find Partition Index
        int partitionIndex = partition(arr, start, end);

        // Recursively call quickSort() for left and right half based on partition Index
        quickSort(arr, start, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, end);
    }
}

int main() {
    int arr[] = { 19, 17, 15, 12, 16, 18, 4, 11, 13 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Printing the original array
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Calling quickSort() to sort the given array
    quickSort(arr, 0, n - 1);

    // Printing the sorted array
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
