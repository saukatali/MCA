#include <stdio.h>
#include <stdlib.h>
int main(){
    int a[5][5], b[5][5], c[5][5];
    int r1,c1,r2,c2, i, j, k; 
    
    printf("Enter the size of Matrix A: ");
    scanf("%d %d", &r1,&c1);
    
    printf("Enter the size of matrix B :");
    scanf("%d %d", &r2,&c2);
    
    if(c1 != r2){
        printf("Matrix Multiplication is Not possible...\n");
        exit(0);
    }
    printf("Enter the Matrix A:\n");
    for(i = 0; i < r1; i++){
        for(j = 0; j < c1; j++){
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the matrix of B:\n");
    for(i = 0; i < r2; i++){
        for(j =0; j < c2; j++){
            scanf("%d", &b[i][j]);
        }
    }
    
    // insertion....................
    for(i = 0; i < r1; i++){
        for(j = 0; j < c2; j++){
            c[i][j] = 0;
        }
    }
    
    // matrix multiplication.....................
    for(i = 0; i < r1; i++){
        for(j = 0; j < c2; j++){
            for(k = 0; k < c1; k++){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    // final output///////////////
    for(i = 0; i < r1; i++){
        for(j = 0; j < c2; j++){
            printf("%d ", c[i][j]);
        }printf("\n");
    }return 0;
}
