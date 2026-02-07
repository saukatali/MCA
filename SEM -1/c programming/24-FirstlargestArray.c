#include <stdio.h>

int largestElement(int arr[], int n) {
    int largest = arr[0];

    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }

    return largest;
}

int main() {
    int a[100],n,i;
   printf("Enter the Size:\n");
   scanf("%d",&n);
   
   printf("Enter the el:\n");
   for(i=0;i<n;i++){
       scanf("%d",&a[i]);
   }

    int result = largestElement(a, n);
    printf("Largest element = %d\n", result);

    return 0;
}
