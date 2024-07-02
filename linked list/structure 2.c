#include<stdio.h>
#include<string.h>

struct employee_data {
    char employee_card[100];
    char employee_name[100];
    int employee_salary;
};

int main() {
    struct employee_data s[3];
    for(int i = 0; i < 3; i++) {
        printf("Enter the employee card number for employee %d: ", i + 1);
        scanf("%s", s[i].employee_card);
        printf("Enter the name of employee %d: ", i + 1);
        scanf("%s", s[i].employee_name);
        printf("Enter the salary of employee %d: ", i + 1);
        scanf("%d", &s[i].employee_salary);
    }

    for(int i = 0; i < 3; i++) {
        printf("\nEmployee %d details:\n", i + 1);
        printf("Card number: %s\n", s[i].employee_card);
        printf("Name: %s\n", s[i].employee_name);
        printf("Salary: %d\n", s[i].employee_salary);
    }

    int highest_salary= 0;
    for(int i = 1; i < 3; i++) {
        if(s[i].employee_salary > s[highest_salary].employee_salary) {
          highest_salary = i;
        }
    }

    printf("\nThe employee with the highest salary is: %s\n", s[highest_salary].employee_name);

    return 0;
}
