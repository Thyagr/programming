#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::to_string;

void print_fizzbuzz(int n)
{
    for (int j = 1; j <= n; j++)
    {
        std::string fizzbuzz;
        if (j%3 == 0)
        {
            fizzbuzz += "fizz";
        } 
        if (j%5 == 0)
        {
            fizzbuzz += "buzz";
        }
        if (fizzbuzz.empty())
        {
            fizzbuzz = std::to_string(j);
        }
        std::cout << fizzbuzz << " ";
    }
}

int main()
{
    int n = 10;
    print_fizzbuzz(n);

    return 0;
}