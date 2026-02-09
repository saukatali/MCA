#include <stdio.h>

void linear_search() {
    int arr[10], size, search, i, found = 0;

    printf("Enter array size (max 10): ");
    scanf("%d", &size);

    printf("Enter array elements:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Array elements are:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nEnter element to search: ");
    scanf("%d", &search);

    for (i = 0; i < size; i++) {
        if (arr[i] == search) {
            found = 1;
            break;
        }
    }

    if (found == 1)
        printf("Element Found\n");
    else
        printf("Element Not Found\n");
}

// Binary Search
void binary_search() {
    int arr[10], size, search, found = 0;
    int start, end, mid;

    printf("Enter array size (max 10): ");
    scanf("%d", &size);

    printf("Enter elements in ascending order:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Array elements are:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nEnter element to search: ");
    scanf("%d", &search);

    start = 0;
    end = size - 1;

    // Replacing while with for loop
    for (int i = 0; start <= end; i++) {
        mid = (start + end) / 2;

        if (arr[mid] == search) {
            found = 1;
            break;
        } else if (search < arr[mid]) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    if (found == 1)
        printf("Element Found\n");
    else
        printf("Element Not Found\n");
}

int main() {
    int choice;

    do {
        printf("\n1. Linear Search");
        printf("\n2. Binary Search");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                linear_search();
                break;
            case 2:
                binary_search();
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 3);

    return 0;
}

