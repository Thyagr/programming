#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

class String_Man
{
private:
    char* str;
    int len;
public:
    String_Man(int length)
    {
        str = new char[length];
        cout << endl << "Enter the string: ";
        cin >> str;
        for (len=0; str[len] != '\0'; len++);
    }
    void uppercase();
    void lowercase();
    void printstr();
    void reversestr();
    bool hasrepeated();
};
void  String_Man::uppercase()
{
    int i = 0;
    while (str[i] != '\0')
    {
        putchar(toupper(str[i]));
        i++;
    }
    string x = "string library";
    cout << endl <<  x;
}

void String_Man::lowercase()
{

}

void String_Man::printstr()
{
    cout << "\nPrinting: ";
    for (int  i=0; str[i] != '\0'; i++)
    {
        printf("%c", str[i]);
    }
    //cout << str;
}

void String_Man::reversestr()
{
    //calc for practice
    int length = 0;
    char c;
    for (;str[length] != '\0'; length++);
    cout << length << endl;
    for (int i=0, j = length-1; i < j; i++,j--)
    {
        cout << str[i] << endl;
        c = str[i];
        str[i] = str[j];
        str[j] = c;
    }
    cout << endl << str << " rev" << endl;

    /*
    void strrev(char str[])
    {
        int len = strlen(str);
        int i =0, j = len-1;
        char temp;
        while (i <= j)
        {
            temp = str[i];
            str[i++] = str[j];
            str[j--] = temp;
        }
    }

    */
}

bool String_Man::hasrepeated()
{
    /*method1 double for - bad O(n2)
    for (int i=0; i<len; i++)
    {
        for (int j=i+1; j<len; j++)
        {
            if (str[i] == str[j]) return true;
        }
    }
    return false;
    */

    /* method2 sort and scan - O(nlogn) + O(n)*/
    sort(str,str+len-1,std::greater<char>());
    for (int j=0; j<len-2; j++)
    {
        if (toupper(str[j]) == toupper(str[j+1])) return true;
    }
    return false;
}
int main(void)
{
//    char* str1;
//    char* str2;
//    str1 = (char*)malloc(sizeof(char)*30);
//    str2 = new char[30];
//    printf ("Enter string1: ");
//    scanf(" %s", str1);
//    cout << "Enter string2: ";
//    cin >> str2;
//    printf("String1: %s", str1);
//    cout <<"\nString2: :" <<str2;
//    cout << endl;

    String_Man obj(20);
    //obj.uppercase();
    //obj.printstr();
    obj.reversestr();
    obj.printstr();
    cout << endl;
    obj.hasrepeated() ? cout << "Repeated" : cout << "Not repeated";
    cout << "\nSorted String: ";
    obj.printstr();

    return 0;
}
