// Online C compiler to run C program online
#include <stdio.h>


void main() {
    
   int a,b,temp;
   
   printf("Enter a,b \n");
   scanf("%d %d",&a,&b);
   
   temp = a;
   a = b;
   b = temp;
   
   printf("a = %d b = %d \n", a , b);
    
}