#include<stdio.h>

int liner(int arr[], int size, int find) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == find) {
            printf("Element is found at index %d\n", i);
            return i;
        }
    }
    printf("Element is not found in the array\n");
    return -1;
}

int main() {
    int arr[] = {12, 23, 36, 40, 44, 85};
    int find = 44;
    int size = sizeof(arr) / sizeof(arr[0]);
    liner(arr, size, find);
    return 0;
}
