#include <stdio.h>
#include <conio.h>

void main()
{
    int arr[] = {50,40,10,20,30}, i,j,n = 5,t;

    for(i=0; i < n; i++)
    {
        for(j=i+1; j<n; j++){
            if(arr[i] > arr[j])
            {
                t = arr[j];
                arr[j] = arr[i];
                arr[i] = t;
            }
        }
    }

    printf("Sorted  array : \n");
    for(i = 0; i < n; i++)
    {
        printf("%d \t", arr[i]);
    }
}