#include <stdio.h>

void cylic(int, int);
void acyclic(int, int);

int main()
{
    int cycle = 9;
    int n = 2;
    cylic(cycle, n);
    n = 3;
    acyclic(cycle, n);
    return 0;
}

void cylic(int cycle, int n)
{
    printf("Cyclic counter\n");
    int increment = 0;
    for (int i = 0; i < n*cycle; i++)
    {
        printf("%d ", increment);
        increment = (increment + 1) % cycle;
    }
}

void acyclic(int cycle, int n)
{
    printf("\nAcyclic counter\n");
    int decrement = cycle - 1;
    for (int i = 0; i < n*cycle; i++)
    {
        printf("%d ", decrement);
        decrement = (decrement + cycle - 1) % cycle;
    }
}
