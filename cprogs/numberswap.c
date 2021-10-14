#include <stdio.h>

void swapadd(int* a, int* b)
{
    *a = *a+*b;
    *b = *a-*b;
    *a = *a-*b;
}

void swapxor(int* a, int* b)
{
    *a = *a^*b;
    *b = *a^*b;
    *a = *a^*b;
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void)
{
    int a = 10;
    int b = 20;
    printf("Before swap: a = %d b = %d", a, b);
    swapadd(&a, &b);
    swapxor(&a, &b);
    swap(&a, &b);
    printf("\nAfter swap:  a = %d b = %d", a, b);
    return 0;
}
