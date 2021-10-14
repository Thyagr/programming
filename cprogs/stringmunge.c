#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* stringmunge(char* str, char c, size_t len)
{
    char* str2 = malloc(sizeof(char)*len);
    int j = 0;
    for (int i = 0; i < len; i++)
    {
        if (str[i] != c)
            str2[j++] = str[i];
    }
    str2[j] = '\0';
    return str2;
}

int main()
{
    char str[100];
    char c;
    printf("Enter a string: ");
    //scanf(" %s", &str);
    gets(str);
    printf("Enter character to remove: ");
    scanf(" %c", &c);
    char* newstr = stringmunge(str, c, strlen(str));
    printf("New string: %s", newstr);
    return 0;
}
