#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// using qsort function
int comparison(const void* x, const void* y)
{
    // sort ascending
    return ( *(char*)x - *(char*)y ); 
}

void* sort(void* list, size_t len)
{   
    qsort(list, len, sizeof(char), comparison);
}

// move upper and lower case characters to one side
char* move_letters(char* s)
{
    int len = strlen(s) - 1;
    int left = 0, right = len;
    while (left <= right)
    {
        if (s[left] >= 'A' && s[left] <= 'Z')
        {
            char t = s[left];
            s[left] = s[right];
            s[right] = t;
            right--;
        }
        else
        {
            left++;
        }
    }
    return s;
}

// remove all whitespaces from string
// void trim_whitespaces(char* s)
// {
//     int len = strlen(s) - 1;
//     for (int i = 0; i < len-1; i++)
//     {
//         if (s[i] == ' ')
//         {
//             s[i] = s[i+1];
//         }
//     }
// }


int firstUniqChar(char * s)
{
    int arr[26] = {0}; // like dict for strings
    int len = strlen(s);   
    int i;
    for (i = 0; i < len; i++)
        arr[s[i] - 'a'] += 1;
    
    for (i = 0; i < len; i++) {
        if (arr[s[i] - 'a'] == 1)
            return i;
    }
    
    return -1;
}

int main()
{
    char string[50];
    // scanf read string with spaces
    scanf("%[^\n]", &string);
    char* s = move_letters(string);
    printf("%s\n", s);
    
    sort(string, strlen(string));
    printf("%s", string);

    int z = firstUniqChar(string);
    printf(" %d", z);

    return 0;
}