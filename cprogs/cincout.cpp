#include <iostream>
#include <stdio.h>
using namespace std;

int main(void)
{
    int charcount = 0;
    const char enter = '\n';

    char ch;
    cout<<"Enter characters: ";
    cin.get(ch);
    while(ch != enter)
    {
        cout.put(ch); // the output will be buffered
        ++charcount;
        cin.get(ch);
    }
    cout<<endl;
    cout<<"Total number of characters entered " << charcount;
    ch = getchar();
    return 0;
}
