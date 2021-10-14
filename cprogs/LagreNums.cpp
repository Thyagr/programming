#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class BigNum
{
public:
    unsigned char* num1;
    unsigned char* num2;
    unsigned char* AddNum();

};

unsigned char* BigNum::AddNum()
{
    std::vector<char> sum;
    int carry = 0;
    size_t len1 = strlen(reinterpret_cast<const char *>(num1));
    size_t len2 = strlen(reinterpret_cast<const char *>(num2));
    int len = (len1 > len2) ? len1: len2;
    cout << endl << "Number: " << len1 << " ";
    for (int i = len; i >= 0; i--)
    {
        int n1 = int(num1[i] - '0');
        int n2 = int(num2[i] - '0');
        sum.push_back((n1+n2)%10 + '0');
        carry = (n1+n2)/10;
    }
    return nullptr;
}


int main()
{
    unsigned char number1[32] = "12233432423423";
    unsigned char number2[32] = "34234234234";
    BigNum* b1 = new BigNum();
    b1->num1 = number1;
    b1->num2 = number2;
    cout << endl << b1->num1;
    cout << endl << b1->num2;
    unsigned char* sum = b1->AddNum();


    return 0;
}
