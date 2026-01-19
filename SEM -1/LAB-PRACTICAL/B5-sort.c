#include <stdio.h>

int main(){
    int a[50];
    int i, j, n, temp;
    
    printf("Enter the size of Array:\n");
    scanf("%d", &n);
    
    printf("Enter the Elements:\n");
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    
    // Bubble Sort Logic
    for(i = 0; i < n - 1; i++){
        for(j = 0; j < n - 1 - i; j++){
            if(a[j] > a[j + 1]){
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    
    printf("Sorted Elements are:\n");
    for(i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    
    return 0;
}
