#include <stdio.h>

int isSort(int[], int);
void main() {
    int arr[10];
    int n, i;

    printf("Enter an n : ");
    scanf("%d", &n);
    printf("Enter an array elements : \n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int result = isSort(arr, n);
    if(result) {
        printf("Array is sorted\n");
    } else {
        printf("Array is not sorted\n");
    }
}

int isSort(int arr[], int n) {
    int i;
    for(i = 0; i < n-1; i++) {
        if(arr[i] >= arr[i+1]){
            return 0;
        }
    }
    return 1;

}

