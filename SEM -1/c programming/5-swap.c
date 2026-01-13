// without using third oprator..
#include <stdio.h>


void main() {
    
   int a,b,temp;
   
   printf("Enter a,b \n");
   scanf("%d %d",&a,&b);
   
   a= a + b;
   b = a - b;
   a = a - b;
   
   printf("a = %d b = %d \n", a , b);
    
}