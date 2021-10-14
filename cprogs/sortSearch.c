
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void array_print(int* arr, int len)
{
    printf("Array = ");
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int cmpfunc (const void * a, const void * b) 
{
   return ( *(int*)a - *(int*)b );
}

int binary_search(int* arr, int len, int value)
{
    int left = 0, right = len-1;
    int mid;
    
    while (left <= right)
    {
        mid = (left + right)/2;
        if (value < arr[mid]) right = mid-1;
        else if (value > arr[mid]) left = mid+1;
        else return mid;
    }
    
    return -1;
}

int main()
{
    srand(time(0)); 
    int len = rand() % 20;
    int arr[len];
    for (int i = 0; i < len; i++)
    {
        arr[i] = rand() % 100;
    }
    
    qsort(arr, len, sizeof(int), cmpfunc);
    array_print(arr, len);
    
    int val = arr[(rand() % len -1)];
    printf("Value = %d\n", val);
    
    int ret = binary_search(arr, len, val);
    printf("Value pos = %d\n", ret);
    
    return 0;
}
