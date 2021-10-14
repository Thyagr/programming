/*
This is an optimized solution for the puzzle of '3 candies' 
posed  Jon Morishita.
cost of each candy is $10, $3, $0.5
total no. and total cost must be = 100
*/

using namespace std;
#include <iostream>

int main(void)
{
    for (int z = 82; z < 100; z+=2)
    {
        int b1 = 100 - 0.5*z;
        int b2 = 100 - z;
        if ( (b1 - 3*b2)%7 == 0)
        {
            if ( (-b1 + 10*b2)%7 == 0)
                cout << (b1 - 3*b2)/7<<" "<<(-b1 + 10*b2)/7<<" "<<z<<"\n";
        }
    }
    return 0;
}

