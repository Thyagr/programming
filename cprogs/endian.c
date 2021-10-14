#include <stdio.h>
#include <stdint-gcc.h>
/*
	higher memory 32 bit machine
          ----->
    +----+----+----+----+
    |0x01|0x00|0x00|0x00|
    +----+----+----+----+
    A &i
  */

uint32_t ChangeEndian(uint32_t num)
{
    //0xAABBCCDD -> 0xDDCCBBAA
    uint32_t revendian = 0;
    revendian |= (num & 0x000000FF) << 24;
    revendian |= (num & 0x0000FF00) << 8;
    revendian |= (num & 0x00FF0000) >> 8;
    revendian |= (num & 0xFF000000) >> 24;
    return revendian;   
}

int main(void)
{
    unsigned int i = 0x55; // int, first bit is sign bit so use max 127
    unsigned char* p = (unsigned char*)&i;
    (*p == 0x55) ? printf("%s\n", "little endian") : printf("%s\n", "big endian");

//    printf("%p\n",(void*) &i);
//    printf("%d\n", (int)(*p));
//    printf("\n");
//    unsigned int j = 0x0A0B0C0D;
//    //int k;
//    unsigned char* q = (unsigned char*)&j;
//    //printf("%d\n",  (unsigned char)strtol(q, NULL, 16));
//    size_t k;
//    for (k=0; k < sizeof(unsigned int); k++)
//    	printf("%x\n",*(q + k));

    uint32_t l = 0x8539AB13;
    uint32_t m = ChangeEndian(l);
    printf("Number = %x -> Changed Endian = %x", l, m);
    return 0;
}
