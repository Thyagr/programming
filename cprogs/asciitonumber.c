#include <stdio.h>
#include <stdlib.h>

#define GETDIGIT(x) ((x) - '0')

/*
Custom implementation of atoi
*/
int AsciiToNumber(const char* numstr)
{
    int sign = 1;
    int inum = 0;
    int i = 0;
    int digit;
    if (numstr[0] == '-')
    {
        i++;
        sign = -1;
    }
    for (; numstr[i] != '\0'; i++)
    {
        digit = GETDIGIT(numstr[i]);
        if (digit > 9 || digit < 0)
        {
                printf("Incorrect input, partial result only\n");
                return inum;
        }
        inum = inum*10 + digit;
    }
    return sign*inum;
}

float AsciiToFloat(const char* numstr)
{
    int sign = 1, i = 0, digit;
    float fnum = 0.0;
    if (numstr[0] == '-')
    {
        i++;
        sign = -1;
    }
    for (; numstr[i] != '\0'; i++)
    {
        if (numstr[i] == '.')
        {
            fractional = 1;
        }
        digit = GETDIGIT(numstr[i]);
        if (digit > 9 || digit < 0)
        {
                printf("Incorrect input, partial result only\n");
                return fnum;
        }
       // call atoi?
    }
}

int main()
{
    char numstr[20];
    printf("Enter a number: ");
    gets(numstr);
    int ret = AsciiToNumber(numstr);
    printf("Number representation: %d, +100 = %d", ret, ret+100);
    return 0;
}
