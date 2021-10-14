#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool IsSubString(char str1[], char str2[])
{
    for (int i=0; str1[i] != '\0'; i++)
    {
        if (str1[i] == str2[0])
        {
            int j = 0;
            while (str1[i+j] != '\0' && str2[j] != '\0')
            {
                if (str1[i+j] != str2[j])
                    break;
                j++;
            }
            if (str2[j] == '\0')
                return true;
        }
    }
    return false;
}

// implementation of strstr function
/*
|39|error: return discards 'const' qualifier from pointer target type [-Wdiscarded-qualifiers]|
is an issue with strstr function definition
*/
char* strstrf(char* str1, char* str2)
{
    for (int i=0; str1[i] != '\0'; i++)
    {
        if (str1[i] == str2[0])
        {
            int j=0;
            while (str1[i+j] != '\0' && str2[j] != '\0')
            {
                if (str1[i+j] != str2[j])
                    break;
                j++;
            }
            if (str2[j] == '\0')
                return (str1 + i);
        }
    }
    return NULL;
}

int main(void)
{
    char str1[] = "Hello World, how are you doing?";
    char str2[] = "World";
    if (IsSubString(str1, str2))
        printf("\"%s\" is a substring of \"%s\"", str2, str1);
    else
        printf("\"%s\" is NOT a substring of \"%s\"", str2, str1);

    return 0;
}
