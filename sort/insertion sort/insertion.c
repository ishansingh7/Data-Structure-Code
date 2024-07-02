#include<stdio.h>

void insertion(int arr[], int size) {
    int temp, i, j;
    for(i = 0; i < size; i++) {
        temp = arr[i];
        j = i - 1;
    // checking the condition if j is greater than 0 and arr[j] is greater temp or not 
    // if j is greater it will enter into loop otherwise it will exit 
        while(j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        } 
        arr[j + 1] = temp; // if condition is false then it will excuted this program 
    }
}

void print(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {6, 3, 7, 1, 7, 4, 9, 2, 5, 8};
    int size = sizeof(arr) / sizeof(arr[0]); 
    insertion(arr, size);
    print(arr, size);
    return 0;
}
