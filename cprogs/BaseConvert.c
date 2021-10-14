#include <stdio.h>

void BaseConvert(unsigned int num, unsigned int base)
{
    if (num >= base)
        BaseConvert(num/base, base);
    (num%base < 10) ? printf("%d", num%base): printf("%0x", num%base);
    /* printf("%u ", num%base); --> any base, space separated */

}

int main(void)
{
    unsigned int num;
    unsigned int base;
    printf("Enter a number: ");
    scanf("%u",&num);
    printf("Enter base factor: ");
    scanf("%u", &base);

//    if (base > num)
//    {
//        printf("Base must be less than the number!");
//        return -1;
//    }
    BaseConvert(num, base);
    return 0;
}
