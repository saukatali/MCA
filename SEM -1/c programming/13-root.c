// find c = root a+b * 1
#include <stdio.h>

#include <math.h>

void main(){
    float a,b,c;
    printf("Enter a and b : \n");
    scanf("%f %f",&a,&b);
    
    c =sqrt(a+b);
    
    printf("c = %f \n",c);
}
