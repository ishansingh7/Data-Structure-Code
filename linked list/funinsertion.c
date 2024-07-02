#include <stdio.h>

void insertion(int arr[], int size, int element, int position);

int main() {
    int arr[] = {15, 20, 25, 30, 35}; 
    int size = 5;
    int element = 23;
    int position = 2;

    printf("Array before insertion:\n");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    insertion(arr, size, element, position);
   size++;

    printf("Array after insertion:\n");
    for(int i = 0; i < size ; i++) {
        printf("%d ", arr[i]);
        
    }
    printf("\n");

    return 0;
}

void insertion(int arr[], int size, int element, int position) {
    for(int i = size - 1; i >= position; i--) {
        arr[i + 1] = arr[i];
    }
    arr[position] = element;
}
