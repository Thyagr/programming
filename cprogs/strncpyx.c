#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Difference, strcpy stops at NULL
*/

void strncpyx(char* s, char* d)
{
    //while exits on NULL
    while ((*d++ = *s++));
}

void memcpyx(void* src, void* dst, size_t bytes)
{
    // typecast to char* to increment byte by byte
    char* s = (char*)src;
    char* d = (char*)dst;
    size_t i = 0;
    while (i < bytes)
    {
        d[i] = s[i];
        i++;
    }
//    for (size_t j=0; j<bytes; j++)
//        d[j] = s[j];
}

int main(void)
{
    char src[] = "Hello World, this is a long sentence";
    /* allocating size
    The size can be anything(?) because we just keep incrementing bytes
    and will just trample over heap, but then cannot use free correctly
    Note: Cannot determine sizeof of a char* array, only obtained during runtime
    need
    */
    char* dst = malloc(sizeof(src));
    strncpyx(src, dst);
    printf("Original: %s\nCopied string: %s", src, dst);
    printf("\nSizeof src %u, sizeof dst %u", sizeof(src), sizeof(dst));
//    char* x = "a";
//    printf("\nSizeof(x) is %u", sizeof(x)); //char pointer is 4
    return 0;
}
