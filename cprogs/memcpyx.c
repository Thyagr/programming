#include <stdio.h>
#include <stdlib.h>

//void* for generic pointer
void memcpyx(void* src, void* dst, size_t len)
{
    //need to cast to char* to increment byte by byte
    char* s = (char*)src;
    char* d = (char*)dst;
    size_t i;
    for (i = 0; i < len; i++)
    {
        d[i] = s[i];
    }
    /* Another:
    while (i < len)
    {
        *d++ = *s++;
        i++;
    }*/
    /*
    for optimization use long*, check if memory is aligned, divide sizeof(long)
    and for the rest do char copy
    */
}

// implement memset, memmove & optimized memcpy

void memsetx(void* src, char c, size_t bytes)
{
    char* s = (char*)src;
    for (size_t i = 0; i < bytes; i++)
    {
        *(s+i) = c;
    }
}

int main(void)
{
    char p[] = "This is a day! ewrwr";
    char* q = malloc(sizeof(p));
    memcpyx(p, q, sizeof(p));
    memsetx(q, '*', 10);

    //print, here just strings, other data types
    //cast appropriately and print
    printf("%s\n", p);
    printf("%s", q);
    return 0;
}
