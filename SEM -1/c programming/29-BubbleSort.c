#include <stdio.h>
#include <conio.h>

void main()
{
    int arr[] = {50,40,10,20,30}, i,j,n = 5,t;

    for(i=0; i < n-1; i++)
    {
        for(j=0; j < n - i - 1; j++){
            if(arr[j] > arr[j+1])
            {
                t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
            }
        }
    }

    printf("Sorted  array : \n");
    for(i = 0; i < n; i++)
    {
        printf("%d \t", arr[i]);
    }
}