#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* reverse(char* s)
{
    int len = strlen(s) - 1; // without the null
    printf("len=%d\n", len);
    for (int i = 0; i <= len/2; i++)
    {
        char t = s[i];
        s[i] = s[len-i];
        s[len-i] = t;
    }
    return s;
}

char* string_compress(char* s)
{
    int arr[26] = {0};
    int len = strlen(s);
    int i;
    for (i = 0; i < len; i++){
        arr[s[i] - 'a'] += 1;
        // printf(" %d-%c ", s[i] - 'a', s[i]);
    }

    // for (i = 0; i < 26; i++)
    //     printf("%d ", arr[i]);

    // get the required size
    int one = 0, two = 0;
    for (i = 0; i < 26; i++)
    {
        if (arr[i] == 0) continue;
        if (arr[i] == 1) one += 1;
        else two += 2;
        // printf(" %d %d %d ", arr[i], one, two);
    }

    int newlen = two + one + 1; // for null
    // printf("\nnew len : %d", newlen);
    char* s2 = (char*)malloc(sizeof(char) * newlen);
    s2[newlen-1] = '\0';
    int j = -1;
    for (i = 0; i < 26 && j < newlen; i++)
    {
        if (arr[i] == 0) continue;
        if (arr[i] == 1)
        {
            s2[++j] = (char)('a' + i);
        }
        else
        {
            s2[++j] = (char)('a' + i);
            s2[++j] = (char)(arr[i] + '0');
        }   
    }
    return s2;
}

int main()
{
    // char p[] = "this is a long sentense";
    // char* i = reverse(p);
    // printf("i=%s\n", i);
    
    char a[11] = {'b', 'a', 'a', 'b', 'b', 'e', 'f', 'c', 'c', 'f'};
    char* s = string_compress(a);

    printf("compressed array: %s", s);


    return 0;
}
