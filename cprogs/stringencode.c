#include <stdio.h>

int main()
{
    const char str[] = "This is a Random String"; //use only lower case
    int lettercount[26] = {0}; // for each alphabet
    char l;
    /*
    Count occurence of each letter,
    array of 26 acts like a dictionary
    This method can also be used for
    checking for anagrams
    */
    for (int i = 0; str[i] != '\0'; i++)
    {
        //l = str[i] | ' '; // OR with space always lowercase
        l = str[i] & '_'; // AND with underscore always uppercase
        //lettercount[l-'a'] += 1;
        lettercount[l-'A'] += 1;
    }
    printf("Original string: %s\n", str);
    printf("Letter count\n");
    for (int j = 0; j < 26; j++)
    {
        if (lettercount[j])
        {
            //printf("%c = %d\n", 'a'+ (char)j, lettercount[j]);
            printf("%c = %d\n", 'A'+ (char)j, lettercount[j]);
        }

    }
    return 0;
}
