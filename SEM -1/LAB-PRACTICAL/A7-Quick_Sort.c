#include <stdio.h>

int partition(int arr[], int low, int high);

void quicksort(int arr[], int low, int high){
    int pos;
    if (low < high){
        pos = partition(arr, low, high);
        quicksort(arr, low, pos - 1);
        quicksort(arr, pos + 1, high);
    }
}

int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int temp;

    // Loop to find the correct position for pivot
    for (;;) {
        // Move i to the right while arr[i] <= pivot
        for (; i <= high && arr[i] <= pivot; i++)
            ;

        // Move j to the left while arr[j] > pivot
        for (; arr[j] > pivot; j--)
            ;

        // If i < j, swap elements
        if (i < j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        } else {
            break;  // Exit the loop if i >= j
        }
    }

    // Move pivot to the correct position
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

int main()
{
    int arr[100], n, i;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Original array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    quicksort(arr, 0, n - 1);

    printf("\nSorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
