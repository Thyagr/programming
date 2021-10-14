#include <iostream>
using namespace std;

bool validatestr(string str)
{
    if (str.length() == 0) return false;
    for (int i=0; i< str.length(); i++)
    {
        if (!(str[i] == '1' || str[i] == '0' || str[i] == '?'))
            return false;
    }
    return true;
}

void printpatterns(string str, int index)
{
    if (index == str.length())
    {
        cout << endl << str;
        return;
    }

    if (str[index] == '?')
    {
        str[index] = '0';
        printpatterns(str, index+1);
        str[index] = '1';
        printpatterns(str, index+1);
    }
    else
        printpatterns(str,index+1);

}


int main (void)
{
    string str;
    cout << "Enter a binary string with wild characters\n";
    cout << "E.g. 11?0??1?0: ";
    cin >> str;

    if (validatestr(str))
    {
        cout << endl << "Valid string: " << str << " length: " << str.length();
        cout << endl << "Patterns";
        printpatterns(str,0);

    }
    else
    {
        cout << endl << "Invalid string!";
    }
    cout << endl;
    return 0;
}
