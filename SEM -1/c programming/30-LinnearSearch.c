#include <stdio.h>
#include <conio.h>

void main()
{
    int arr[10], n, i, j, key=5, f = 0;

    printf("Enter the N : ");
    scanf("%d", &n);

    printf("Enter the array : \n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Entered  array : \n");
    for(i = 0; i < n; i++)
    {
        printf("%d \t", arr[i]);
    }

    for(i = 0; i < n; i++)
    {
        if(arr[i] == key)
        {
            f = 1;
            break;
        }
    }

    if(f == 1)
    {
        printf("Its in array \n");
    }
    else
    {
        printf("not in array");
    }

}