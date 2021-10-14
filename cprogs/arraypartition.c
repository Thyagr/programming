#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define LENGTH 25

void printarray(int arr[], int len)
{
    for(int j=0; j<len; j++)
        printf("%d ", arr[j]);
}

void swap(int* p, int* q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

/*
partition the array into odd and even parts
*/
void arraypartition(int arr[], int len)
{
    int left = 0, right = len-1;
    while (left < right)
    {
        if (arr[left]%2 == 0)
        {
            swap(&arr[left], &arr[right]);
            right--;
        }
        else
            left++;
    }
}

int main()
{
    srand(time(NULL));
    int arr[LENGTH];
    for (int j=0; j<LENGTH; j++)
    {
        arr[j] = rand()%100; //numbers from 0 - 100
    }
    printf("Original array:  ");
    printarray(arr, LENGTH);
    arraypartition(arr, LENGTH);
    printf("\nAfter partition: ");
    printarray(arr, LENGTH);
    return 0;
}
