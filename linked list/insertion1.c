#include <stdio.h>

int main(void) {
    int array[] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
    int size = 10;
    int element = 15;
    int position = 5;

    printf("Elements before insertion:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

   
    for (int i = size - 1; i >= position; i--) {
        array[i + 1] = array[i];
    }
    array[position] = element;
    size++;

    printf("Elements after insertion:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
