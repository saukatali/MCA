#include <stdio.h>

int main() {
    int a[5];
    int i, j, min, temp,n;
    
    printf("Enter the size:\n");
    scanf("%d",&n);
    
    printf("Enter the Elemets:\n");
    for(i =0; i <n ;i++){
        scanf("%d",&a[i]);
    }
    for(i = 0; i < n; i++) {
        min = i;
        for(j = i + 1; j < n; j++) {
            if(a[j] < a[min]) {
                min = j;
            }
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }

    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
