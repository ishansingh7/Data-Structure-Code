#include<stdio.h>
#include<string.h>

struct car_data {
    int id;
    char model[100];
    int rental_rate;
    int rental_days;
};

int main() {
    struct car_data s[3];
    for(int i = 0; i < 3; i++) {
        printf("Enter the car ID number %d: ", i + 1);
        scanf("%d", &s[i].id);
        printf("Enter the model of car %d: ", i + 1);
        scanf("%s", s[i].model);
        printf("Enter the rental rate and number of rental days for car %d: ", i + 1);
        scanf("%d %d", &s[i].rental_rate , &s[i].rental_days);
        
    }

    for(int i = 0; i < 3; i++) {
        printf("\nCar %d details:\n", i + 1);
        printf("Car ID: %d\n", s[i].id);
        printf("Model: %s\n", s[i].model);
        printf("Rental Amount: %d\n", s[i].rental_rate * s[i].rental_days);
    }

    return 0;
}
