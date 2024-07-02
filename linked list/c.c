
#include <stdio.h>
//int reverse(int x);


int main()
{
    char x[] = 'ishan ';
 printf("the given character is %s\n", x);
  char reverce= 0;
  while( x != 0){
    int remainder= x[] %10;
    reverce=  reverce*10 + remainder;
     x[] /= 10;

  }
printf("the reverse of the given character is %s\n", reverce);
  return 0 ;

}
/*int reverse(int x)
{
    int reversed = 0;
    while(x != 0){
        int remainder = x % 10;
        reversed = reversed *10 + remainder;
        x = x /10;
    }

return reversed ;*/

