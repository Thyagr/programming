
#include <stdio.h>

int my_atoi (char* num, int len)
{
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        if (num[i] <= '0' || num[i] >= '9') return -1;
        sum = (sum*10) + (num[i]-'0');
    }
    return sum;
}

int
main ()
{
  char num[] = "234";
  int len = sizeof(num)/sizeof(num[0]) - 1;
  int n = my_atoi (num, len);
  printf ("String: %s\nNumber: %d", num, n);
  return 0;
}
