
#include <stdio.h>
#include <conio.h>

void main() {
 
  int a,b,c,big,small,sl;

    printf("Enter r\n");
    scanf(" %d %d %d",&a, &b, &c);
    big = a;
        if(b>big){
        //printf("B is bigger\n");
        big = b;
    }
       if(c>big){
        //printf("C is bigger\n");
        big = c;
    }
    small = a;
        if(b<small){
        //printf("B is bigger\n");
        small = b;
    }
       if(c<small){
        //printf("C is bigger\n");
        small = c;
    }
    sl = a + b + c - small - big;
    printf("big = %d sl = %d small = %d", big, sl, small);
    getch();

    // return 0;
}
