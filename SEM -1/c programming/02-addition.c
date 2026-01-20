// Addition...............

#include <stdio.h>

void main(){
    int a,b,c;
    
    printf("Ente a &b:");
    scanf("%d %d",&a,&b);
    
    c = (a *a - b * b) / (a-b);
    
    printf("%d",c);
    
}
