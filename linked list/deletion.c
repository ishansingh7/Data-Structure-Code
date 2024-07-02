#include <stdio.h>

int main() {
    int arr[] = {15, 20, 25, 30, 35}; 
    int size = 5;
    int position = 2; 
    printf("Array before deletion:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);    
    }
    printf("\n");

   
    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--; 

    printf("Array after deletion:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
