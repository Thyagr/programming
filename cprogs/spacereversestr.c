#include <stdio.h>
#define DEBUG 1
void revstr(char* str, int c, int j)
{
    //char* temp = malloc(sizeof(char));
    char temp;
    while (c <= j)
    {
        temp = str[c];
        str[c] = str[j];
        str[j] = temp;
        j--;
        c++;
    }
}

void parsestr(char* str)
{
    int j = 0;
    int c = 0;
    while (str[j] != '\0')
    {
        while(str[j] != '\0' && str[j++] == ' '); j--;
        c = j;
        while (str[j] != '\0' && str[j++] != ' ');
        if (DEBUG) printf("\nWord splits: %d %d", c, j-1);
        revstr(str,c,j-1);
    }
}

int main (void)
{
    char str[100];
    int i;
    printf("Enter a string: ");
    fgets(str,100,stdin);
    printf("\nOriginal string:");
    for (i = 0; str[i] != '\0'; i++)
            printf("%c",str[i]);
    str[i-1] = '\0'; //fgets adds a newline at the end
    parsestr(str);
    printf("\nWords reversed string:");
    for (i = 0; str[i] != '\0'; i++)
    {
        //if (str[i] == '\n') printf("bingo");
        printf("%c",str[i]);
    }

    return 0;
}
