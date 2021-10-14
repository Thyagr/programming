#include <stdio.h>
#include <stdlib.h>

#define BYTES 512 // usually integral multiple of alignment
#define ALIGN 128 // power of 2

void* allignedmalloc(size_t numbytes, size_t align)
{
    int offset = align - 1 + sizeof(void*);
    void* p1 = malloc(numbytes + offset);
    if (p1 == NULL)
        return NULL;
    void** p2 = (void**)(((size_t)p1 + offset) & ~(align -1));
    p2[-1] = p1;
    return p2;
}

void allignedfree(void* p2)
{
    void* p1 = ((void**)p2)[-1];
    free(p1);
}

int main()
{
    size_t bytes = BYTES, alignment = ALIGN;
    void* ptr2 = malloc(bytes);
    void* ptr  = allignedmalloc(bytes, alignment);
    printf("Aligned Memory = %p, Unaligned = %p", ptr, ptr2);
    return 0;
}
