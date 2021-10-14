#include <stdio.h>

unsigned long fact(int x)
{
    if (x == 0) return 1;
    else return x*fact(x-1);
}

// O(n)
unsigned long exponent_std(int x, int n)
{
    if (n == 1) return x;
    else return x*exponent_std(x,n-1);
}

// O(logn)
unsigned long exponent_split(int x, int n)
{
    if (n == 0) return 1;
    if (n%2 == 0)
    {
        //temp variable to avoid making same call to recursion
        int y = exponent_split(x,n/2);
        return y*y;
    }
    else
    {
        return x*exponent_split(x,n-1);
    }
}

// (X^n)%M
int modulo_remainder(int x, int n, int M)
{
    if (n == 0) return 1;
    if (n%2 == 0)
    {
        int y = modulo_remainder(x,n/2,M);
        return ((y%M)*(y%M))%M;
    }
    else
    {
        return ((x%M)*modulo_remainder(x,n-1,M)%M);
    }
}

void binary_representation(int x)
{
    /*forward print*/
    if (x > 1) binary_representation(x/2);
    printf("%d",x%2);

    /*reverse print*/
    printf("%d",x%2);
    if (x > 1) binary_representation(x/2);

}

int main(void)
{
    int x,n,M;
    printf("Enter a number  (x) : ");
    scanf(" %d", &x);
    printf("Enter the power (n) : ");
    scanf(" %d", &n);
    printf("%d %d", x, n);
    printf("\nBinary representation          : ");
    binary_representation(x);
    printf("\nExponent1 Std O(n) Recursion   : %lu",exponent_std(x,n));
    printf("\nExponent2 O(logn) Recursion    : %lu",exponent_split(x,n));
    printf("\nFactorial Recursion            : %lu",fact(x));
    printf("\nBinary representation: ");
    binary_representation(x);
    printf("\n\nEnter modulo number : ");
    scanf(" %d", &M);
    printf("Modulo M Remainder    : %d", modulo_remainder(x,n,M));

    printf("\n");
    getchar();
    return 0;
}
