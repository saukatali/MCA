#include <stdio.h>
#include <conio.h>

void main(){
    int a[3][3], i, j;

    printf("Enter Elements\n");
    for( i = 0; i < 3; i++){
        for( j = 0; j < 3; j++){
            scanf("%d", &a[i][j]);
        }
    }
    printf("The array Elements are : ");
    {
        for(i = 0; i<3; i++){
            for(j=0; j<3;j++){
                printf("%d\t",a[i][j]);
            }
        }
    }
}