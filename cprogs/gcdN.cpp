#include <iostream>
#include <cstdlib>
#include <time.h>
using std::cout;
using std::endl;

// function prototype
int gcd2Numbers (int, int);
int gcd2NumbersMod (int, int);

int main()
{
    const int length = 3;
    srand(time(NULL));
    int arr[length] = {0};
    cout << "Numbers: ";
    for (int j = 0; j < length; j++)
    {
        arr[j] = rand()%100; //numbers from 0 - 100
        cout << arr[j] << " ";
    }

    int gcd = arr[0];
    for (int i = 0; i < length; i++)
        gcd = gcd2NumbersMod(arr[i], gcd);

    cout << endl << "GCD of the numbers: " << gcd;
    return 0;
}

// function definitions
// subtraction method
int gcd2Numbers (int n1, int n2)
{
    if (n1 == 0) return n2;
    if (n2 == 0) return n1;
    // if (n1 == n2) return n1; // required? NO!

    // keep subtracting the numbers till gcd is reached
    if (n1 > n2)
        return gcd2Numbers(n1-n2, n2);
    else
        return gcd2Numbers(n1, n2-n1);
}

// more efficient modulo method
int gcd2NumbersMod(int n1, int n2)
{
    if (n2 == 0) return n1;
    return gcd2NumbersMod(n2, n1%n2);
}
