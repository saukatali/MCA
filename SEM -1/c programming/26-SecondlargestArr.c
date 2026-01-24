#include <stdio.h>
#include <limits.h>

int secondLargest(int arr[], int n) {
    if (n < 2) {
        return -1; // Not possible
    }

    int largest = INT_MIN;
    int second = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) {
            second = largest;
            largest = arr[i];
        }
        else if (arr[i] > second && arr[i] != largest) {
            second = arr[i];
        }
    }

    if (second == INT_MIN)
        return -1; // No second largest (all elements same)

    return second;
}

int main() {
    int arr[] = {10, 5, 20, 8, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = secondLargest(arr, n);

    if (result == -1)
        printf("Second largest element does not exist\n");
    else
        printf("Second largest element = %d\n", result);

    return 0;
}
