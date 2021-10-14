
#include <stdio.h>
#include <string.h>

void fizz_buzz(int n)
{
    char* f = "fizz";
    char* b = "buzz";
    
    for (int i = 1; i <= n; i++)
    {
        char result[10] = {0};        
        if (i % 3 == 0)
        {
            strcat(result, f);
        }
        if (i % 5 == 0)
        {
            strcat(result, b);
        }
        if (strlen(result) == 0)
        {
            char num[10];
            snprintf(num, sizeof(num), "%d", i);
            strcat(result, num);
        }
        
        printf("%s\n", result);
    }
}

int main()
{
    int n = 15;
    fizz_buzz(n);
    return 0;
}
