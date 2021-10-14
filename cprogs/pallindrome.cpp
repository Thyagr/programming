#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    char word[51];
    cout<<"Enter a word: ";
    cin.getline(word,50);
    int flag = 1;
    for (int i = 0, j = strlen(word)-1; i < strlen(word)/2 ; j--,i++)
    {
        if (word[i] != word[j])
        {
            flag = -1;
            break;
        }
    }
    flag == 1 ? cout<< "Pallindrome" : cout<< "Not a Pallindrome";
    cin.get();
    return 0;
}
