#include <stdio.h>

void SomeFunc()
{
    printf("Some message");
}

int* Add (int x, int y)
{
    int c = x + y;
    return &c; //bad-local variables are destroyed in stack after completion
}

int main(void)
{
    int a = 2, b = 4;
    int* result = Add(a, b);
    printf("%d\n", *result);
    SomeFunc();
    printf("%d\n", *result);
    return 0;
}
