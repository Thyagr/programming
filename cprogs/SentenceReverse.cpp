#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstdio>

void reverseWord(char s[], int left, int right)
{
    char temp;
    for(; left < right; left++, right--)
    {
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;
    }
}

int main()
{
    char str[] = "This is a random  sentence with a bunch of words!";
    char* revstr = (char*)malloc(sizeof(str)/sizeof(str[0]));
    int arrsize = sizeof(str)/sizeof(str[0]);
    int len = arrsize-1; // strlen is size-1
    revstr[len] = '\0'; // make end of array NULL
    int right = len-1; // marker for right end of word
    for(int i = 0, j = len-1; str[i] != '\0'; i++, j--)
    {
        revstr[j] = str[i];
        if (revstr[j] == ' ')
        {
            reverseWord(revstr, j+1, right); // +1 jump 'back'
            right = j-1; // -1 move fwd
        }
    }
    reverseWord(revstr, 0, right); // reverse final word as there may be no space
    printf("\n%s", str);
    printf("\n%s", revstr);
    return 0;
}

