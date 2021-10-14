#include <stdio.h>
#include <stdlib.h>

// check to see if stack grows up or down
void stack_growth()
{
    int x = 1;
    int y = 2;
    
    // %p pointer format 
    printf("%p %p ", &x, &y);
    if (&x > &y) printf("Stack down");
    else printf("Stack up");
}

void check_endian()
{
    /* -------> inc memory
    Lit endian: 0xDDCCBBAA
    Big endian: 0xAABBCCDD
    */
    unsigned int a = 0x55;
    unsigned char* b = (unsigned char*)&a;
    printf("\n");
    if (*b == 0x55) printf("Little endian");
    else printf("Big endian");

}

void cyclic_counter(int cycle)
{
    int c = -1;
    int d = 0;
    // run for 3 cycles
    for (int j = 0; j < 3*cycle; j++)
    {
        c = (c+1)%cycle; // inc counter logic
        d = (d + cycle -1)%cycle; // dec logic
        printf("%d %d\n", c, d);
    }
}


int main()
{
    // stack_growth();
    // check_endian();
    cyclic_counter(5);
    return 0;
}