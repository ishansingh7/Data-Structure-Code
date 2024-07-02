 #include<stdio.h>
 #include <string.h>
 struct student_data{
    char name[100];
    int age;
    int totalmarks;
    };
 int main()
 {
    struct student_data s1;
    printf("enter the name of the student 1: ");
    scanf("%s", s1.name);
     printf("enter the age of the student 1 :");
    scanf("%d", &s1.age);
     printf("enter the totalmarks of the student 1 :");
    scanf("%d", &s1.totalmarks);
    
    struct student_data s2;
     printf("enter the name of the student 2 :");
    scanf("%s", s2.name);
     printf("enter the age of the student 2 :");
    scanf("%d", &s2.age);
     printf("enter the totalmarks of the student 2 :");
    scanf("%d", &s2.totalmarks);

 printf("\n\n--------------------------------------/n");

    printf("the name of the student is %s\n", s1.name);
    printf("the age of the student is %d \n", s1.age);
    printf("the total marks of the student is %d\n",s1.totalmarks);
    printf("\n--------------------------------------/n");
    printf("the name of the student is %s\n", s2.name);
    printf("the age of the student is %d \n", s2.age);
    printf("the total marks of the student is %d\n",s2.totalmarks);

return 0;

 }