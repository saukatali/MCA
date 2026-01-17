//find biggest value between two numbers
#include <stdio.h>

int main() {
    int a,b;
    printf("Enter one value of A:\n");
    scanf("%d",&a);
    printf("Enter second value of B: \n");
    scanf("%d",&b);
    
    if(a >b){
        printf("a is biggrr: %d \n",a);
    }else{
        printf("b is bigger: %d \n",b);
    }

    return 0;

}

