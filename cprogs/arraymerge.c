#include <stdio.h>
#include <stdlib.h>

/*
Merge 2 integer arrays in sequence
Similar concept(cur!=NULL) can be used for linked lists
*/
void arraymerge(int* a, int a_len, int* b, int b_len, int* c)
{
    int i = 0, j = 0, k = 0;
    while (i < a_len && j < b_len)
    {
        if (a[i] <= b[j]) c[k++] = a[i++];
        else c[k++] = b[j++];
    }
    while (i < a_len) c[k++] = a[i++];
    while (j < b_len) c[k++] = b[j++];
}

int main(void)
{
    int a[] = {2,4,6,8};
    int b[] = {1,2,3,4,5,6,7,9};
    int p;
    int a_len = sizeof(a)/sizeof(a[0]);
    int b_len = sizeof(b)/sizeof(b[0]);
    int* c = malloc((a_len+b_len)*sizeof(int));

    printf("\nArray 1: ");
    for (p = 0; p < a_len; p++)
        printf("%d ", a[p]);
    printf("\nArray 2: ");
    for (p = 0; p < b_len; p++)
        printf("%d ", b[p]);

    arraymerge(a, a_len, b, b_len, c);

    printf("\nArray 3: ");
    for (p = 0; p < (a_len + b_len); p++)
        printf("%d ", c[p]);

    return 0;
}
