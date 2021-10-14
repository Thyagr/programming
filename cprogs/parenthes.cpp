#include <iostream>
using namespace std;
#include <stack>
#include <string.h>

class Solution
{
    private:
        string paren_open = "({{";
        string paren_close = ")}]";
    public:
        bool isPalin(int);
        bool isBalance(string);

};

bool Solution::isBalance(string s)
{
    if (s.empty()) return false;

    stack<char> stk;
    for (int i = 0; i < s.length(); i++ )
    {
        if (paren_open.find(s[i]))
            stk.push(s[i]);
        if (paren_close.find(s[i]))
            stk.pop();
    }

    return stk.empty() ? true : false;
}


bool Solution::isPalin(int x)
{
       if (x < 0) return false;
       int dig, rev = 0, num = x; 
       
       while (x > 0)
       {
           dig = x%10; 
           rev = rev*10 + dig;
           x = x/10;
           // cout << x << " " <<  dig << " " << rev;
       }
     return (num == rev) ? true: false;
}

int main (void)
{
    Solution S1;    
    if (S1.isPalin(121)) cout << "\nPalin ";
    else cout << "\nNot Palin";
    S1.isPalin(100) ? cout << "\nPalin " : cout << "\nNot Palin";
    
    S1.isBalance("skf(sfs)sd") ? cout << "\nBalanced" : cout << "\nNot Balanced";
    S1.isBalance("((s)kf(sfs)sd") ? cout << "\nBalanced" : cout << "\nNot Balanced";



    return 0;
}