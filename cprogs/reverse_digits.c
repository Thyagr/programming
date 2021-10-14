
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* reverse(char*);

int main() {
    char num[] = "-12345";
    printf("number  = %s\n", num);
    char* r = reverse(num);
    printf("reverse = %s", r);

    return 0;
}


char* reverse(char* s)
{
    int len = strlen(s);
    // printf("len = %d\n", len);
    char* rev = (char*)malloc(sizeof(char)*(len +1));
    rev[len] = '\0';
    
    if (s[0] == '-')
    {
        rev[0] = '-';
        for (int i = len - 1; i > 0; i--)
        {
            rev[i] = s[len - i];
        }
    }
    else 
    {
        for (int i = len - 1; i >= 0; i--)
        {
            rev[i] = s[len - 1 - i];
        }
    }
    return rev;
}