#include <stdio.h>

/*
Ackermann function: non-primitive recursive, tractable
Useful to simulate stack overflow?
*/
int Ackermann(int m, int n)
{
    if (m == 0) return n+1;
    if (n == 0) return Ackermann(m-1, 1);
    return Ackermann(m-1, Ackermann(m, n-1));
}

int main(void)
{
    int ack = Ackermann(4, 0);
    printf("The Ackermann: %d", ack);
    return 0;
}
