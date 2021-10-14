
#include <stdio.h>

int main()
{
    int i = 3;
    int *j;
    j = &i;

    printf("value of i %d\n",i);
    printf("address of i %u\n",&i);
    printf("value of i %d\n",*(&i));
    printf("value of j %d\n",*j);
	return 0;
}
