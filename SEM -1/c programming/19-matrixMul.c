#include <stdio.h>
#include <stdlib.h>
void main() {
    int i, j, a[3][3], b[3][3], c[3][3];

    printf("Enter A Elements : \n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter B Elements : \n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            scanf("%d", &b[i][j]);
        }
    }
    
     printf("The A Elements are : \n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d \t", a[i][j]);
        }
        printf("\n");
    } printf("The B Elements are : \n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d \t", b[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            c[i][j] = a[i][j] * b[i][j];
        }
    }

    printf(" A x B  : \n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d \t", c[i][j]);
        }
        printf("\n");
    }
  
}