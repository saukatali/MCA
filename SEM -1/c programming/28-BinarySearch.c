#include <stdio.h>

void main()
{
    int n, i, key=20, f = 0, mid;

    // printf("Enter the N : ");
    // scanf("%d", &n);
    int arr[10] = {10,20,30,40,50};
    int low=0, high = 4;
    // printf("Enter the array : \n");
    // for(i = 0; i < n; i++)
    // {
    //     scanf("%d", &arr[i]);
    // }
    // printf("Entered  array : \n");
    // for(i = 0; i < n; i++)
    // {
    //     printf("%d \t", arr[i]);
    // }

    while(low <= high)
    {
        mid = (low+high) / 2;

        if(arr[mid] == key)
        {
            printf("Key is Here\n");
            return;
        }
        else if(arr[mid] > key)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    printf("Key not found\n");
}