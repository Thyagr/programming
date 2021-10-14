#include <iostream>
#include <string>
using namespace std;
#include <stack>
#include <string.h>


bool checkbalance(char* exp)
{
    stack<char> stk;
    char c;
    for (int i=0; i<strlen(exp)-1; i++)
    {
        if (exp[i] == '(')
            stk.push(exp[i]);
        else if (stk.top() == ')')
            stk.pop();
        else return false;
    }
    return true;
}


int main(void)
{
    char bracket_exp[50];

    cout << "Enter the expression: ";
    cin >> bracket_exp;
    bool result = checkbalance(bracket_exp);
    cout << endl << result;

}
