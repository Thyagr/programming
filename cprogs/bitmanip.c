#include <stdio.h>
#include <string.h>

// macro for mask 2^n-1 = n 1's
#define BITMASK(h,l) ((((unsigned int)1 << ((h)-(l)+1)) -1) << (low))
#define BITSET(num, b) ((num) | (1 << (b)))
#define BITCLEAR(num, b) ((num) & ~((unsigned int)1 << (b)))
#define BITCHECK(num, b) (((num) & ((unsigned int)1 << b)) ? 1 : 0)

/*
Note: a macro is a simple text substitution, does not have to be C lang bound
e.g. #define FOO *((unsigned is a valid macro
*/

/* other macros from f2c.h Fortran to C header
#define abs(x) ((x) >= 0 ? (x) : -(x))
#define dabs(x) (doublereal)abs(x)
#define min(a,b) ((a) <= (b) ? (a) : (b))
#define max(a,b) ((a) >= (b) ? (a) : (b))
#define dmin(a,b) (doublereal)min(a,b)
#define dmax(a,b) (doublereal)max(a,b)
#define bit_test(a,b)	((a) >> (b) & 1)
#define bit_clear(a,b)	((a) & ~((uinteger)1 << (b)))
#define bit_set(a,b)	((a) |  ((uinteger)1 << (b)))
*/

void getBinaryRec(unsigned int num) //gives in fwd order, change print order for reverse
{
    if (num > 1) getBinaryRec(num >> 1); // or num/2
    printf("%d", num%2);
}

/* automatically fill in buffer instead of printf
make buffer of required length 32 + 1*/
void binary_print(uint32_t num, char* buf)
{
    if (num > 1) binary_print(num / 2, buf);
    char c[2];
    snprintf(c, 2, "%d", num % 2);
    strcat(buf, c);
}

void getBinary(unsigned int num) //gives in reverse
{
    while (num > 0)
    {
        printf("%d", num%2);
        num = num >> 1;
    }
}

long getBinaryLong(unsigned int num)//bad implementation
{
    unsigned long bin = 0, ten = 1;
    while (num > 0)
    {
        bin = bin + (num%2)*ten;
        num = num/2;
        ten *= 10;
    }
    return bin;
}

int getNthBit(unsigned int num, int nbit)
{
    //return ((num & 1 << nbit) != 0) ? 1 : 0;
    return (num & (1 << nbit)) ? 1 : 0;
}

int setNthBit(unsigned int num, int nbit)
{
    return num | (1 << nbit);
}

int toggleNthBit(unsigned int num, int nbit)
{
    // required bit XOR with 1 = toggle
    // rest of bits XOR with 0 = same
    return num ^ (1 << nbit);
}

int checkIfAllBitsSet(int num)
{
    /* use n & (n-1) == 0 idea here :) Nice hack by me
    if every bit is set then number is 2^n -1 */
    return ((num+1) & num) ? 0 : 1;
}

void exchangeOddEvenBits(unsigned int num)
{
    // for a 32 bit number
    unsigned int even = num & 0xAAAAAAAA;
    unsigned int odd  = num & 0x55555555;
    unsigned int swapnum = (odd << 1) | (even >> 1);
    printf("\nBits swapped num: %u\t", swapnum);
    getBinaryRec(swapnum);
}

void reverseBitsRec(unsigned int num/*, unsigned int* rev*/)
{
    // same idea as printing recursive but the printf first
    *rev = (*rev << 1) + num%2;
    if (num > 1) reverseBitsRec(num/2, rev);
}

unsigned int reverseBits(unsigned int num)
{
    unsigned int rev = 0;
    while (num)
    {
        rev = (rev << 1) + num%2;
        num = num >> 1;
    }
    return rev;
}

unsigned int extractBits(unsigned int num, int hi, int low)
{
    unsigned int mask = 0;
    for (int i = low; i <= hi; i++)
        mask = mask | (1 << i);
    return (num & mask) >> low;
}

unsigned int extractBits2(unsigned int num, int hi, int low)
{
    // logic 2^n-1 = mask of n 1s
    // +1 inclusive of hi
    unsigned int mask = (((unsigned int)1<<(hi-low+1)) - 1) << low;
    return (num & mask) >> low;
}

int countones(unsigned int num)
{
    int ones = 0;
    while (num > 0)
    {
        if (num & 1) ones++;
        num = num >> 1;
    }
    return ones;
}

int countonesKnR(unsigned int num)
{
    int ones = 0;
    while (num)
    {
        /* n & n-1 will always clear LSB
        will run exactly as many times there are ones */
        num = num & (num-1);
        ones++;
    }
    return ones;
}

int main(void)
{
    unsigned int num;
    short unsigned int nth;
    printf("Enter a number: ");
    scanf(" %u", &num);
    getBinary(num);
//    getBinaryRec(num);
//    printf ("\n%ld",getBinary(num));
//
//    printf("\nGet nth bit, enter n:\t");
//    scanf("%hu", &nth);
//    printf("%d", getNthBit(num,nth-1));
//    printf("\nSet nth bit, enter n:\t");
//    scanf("%hu", &nth);
//    num = setNthBit(num,nth-1);
//    getBinaryRec(num);
//    printf ("\n");

    //check if every bit is set
//    int x;
//    printf("\nEnter number to check the bits:\t");
//    scanf("%d", &x);
//    if (checkIfAllBitsSet(x))
//        printf("\nAll the bits are set");
//    else
//        printf("\nNot all bits are 1s");

    /* swapping bits
    // printf("%d",sizeof(unsigned int)); 4 bytes
    unsigned int num;
    printf("Enter a number to swap odd-even bits: ");
    scanf(" %u", &num);
    getBinaryRec(num);
    exchangeOddEvenBits(num);
    */
//    getBinaryRec(num);
//    num = reverseBits(num);
//    printf("\n");
//    getBinaryRec(num);
//        int hi = 4;
//        int low = 1;
      // printf("\n%d ", extractBits(num,hi,low));
//    printf("\n");
//    getBinaryRec(extractBits2(num, hi, low));
//    getBinaryRec(extractBits(num, hi, low));
//    int z = BITMASK(5,4);
//    printf("BITMASK\t");
//    getBinaryRec(z);

    printf("\nOnes in number: %d", countonesKnR(num));
    return 0;
}
