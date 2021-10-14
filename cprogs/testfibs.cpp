#include <iostream>
using namespace std;

int fibIter(int n)
{
    if (n <= 1) return n;
    int i = 2;
    int first = 0, second = 1, third;
    while (i <= n)
    {
        third = first + second;
        first = second;
        second = third;
        i++;
    }
    return third;
}

int fibRec(int n)
{
    if (n <= 1) return n;
    return fibRec(n-1) + fibRec(n-2);
}

int fibDP(int n, int mem[])
{
    if (n<=1) return n;
    mem[0] = 0; mem[1] = 1;
    for (int i =2; i<=n; i++)
        mem[i] = mem[i-1] + mem[i-2];

    return mem[n];
}

int fibDPOptm(int n, int memoptm[])
{
    if (n<=1) return n;
    memoptm[0] = 0; memoptm[1] = 1;
    for (int i =2; i<=n; i++)
    {
        memoptm[2] = memoptm[1] + memoptm[0];
        memoptm[0] = memoptm[1];
        memoptm[1] = memoptm[2];
    }

    return memoptm[2];
}

int main()
{
    int n;
    cout << "Enter the nth number for fib: ";
    cin >> n;
    int mem[n+1];
    //for (int i=0; i<n+1; i++) mem[i] = -1;
    int memoptm[3];
    cout << endl << fibIter(n);
    cout << endl << fibRec(n);
    cout << endl << fibDP(n, mem);
    cout << endl << fibDPOptm(n, memoptm);
    return 0;
}
