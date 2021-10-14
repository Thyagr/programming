#include <stdio.h>
#include <stdlib.h>

// O(n)
int exponent_std(int x, int n)
{
    if (n == 1)
        return x;
    else
        return x * exponent_std(x, n - 1);
}

// O(logn)
int exponent_trick(int x, int n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
    {
        //temp variable to avoid making same call to recursion
        int y = exponent_trick(x, n / 2);
        return y * y;
    }
    else
    {
        return x * exponent_trick(x, n - 1);
    }
}

int fact(int x)
{
    if (x == 0)
        return 1;
    else
        return x * fact(x - 1);
}
int main(void)
{
    int x, n;
    printf("Enter a number : ");
    scanf(" %d", &x);
    printf("Enter the power: ");
    scanf(" %d", &n);
    printf("%d %d", x, n);
    printf("\nExponent1 : %d", exponent_std(x, n));
    printf("\nFactorial : %d", fact(x));
    printf("\nExponent2 : %d", exponent_trick(x, n));
    getchar();
    return 0;
}
