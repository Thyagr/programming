
/*Need to get to n steps in either
1, 2 or 3 steps
# of ways to n steps = # of ways to n-1 + n-2 ...
walks(n) = walks(n-1) + walks(n-2) + ...
Similar problems O(m^n) execution time
here 2^n (1 or 2 steps)
 */

#include <iostream>
using namespace std;



long waystoNstepsRec(int n, long mem[])
{
    if (n <= 0) return 0;
    else if (n == 1) return 1;
    else if (n == 2) return 2;
    else if (n == 3) return 3;
    else
    {
        if (mem[n] == -1)
            mem[n] = waystoNstepsRec(n-1,mem) + waystoNstepsRec(n-2,mem)
                + waystoNstepsRec(n-3,mem);
        return mem[n];
    }
    /* possible optimizations, 'm' type steps
    can use n<=m instead of multiple else ifs
    for loop mem[n] += waystoNstepsRec(n-i,mem)*/
}

long waystoNstepsDP(int n, long mem[])
{
    if (n <= 3) return n;
    mem[1] = 1; mem[2] = 2, mem[3] = 3;

    for (int i=4; i<=n; i++)
    {
        mem[i] = mem[i-1] + mem[i-2] + mem[i-3];
    }
    return mem[n];
}

long waystoNstepsDPOpt(int n)
{
    /*Even more optimized in the space
    consumption as we just use 3 values at
    any given time in the array  */

    if (n <= 3 ) return n;
    long mem[4+1];
    mem[1] = 1; mem[2] = 2, mem[3] = 3;
    for (int i=4; i<=n; i++)
    {
        mem[4] = mem[3] + mem[2] + mem[1];
        mem[1] = mem[2];
        mem[2] = mem[3];
        mem[3] = mem[4];
    }
    return mem[4];
}

int main(void)
{
    int n;
    cout << "Walks to 'n' steps, enter n: ";
    cin >> n;
    //array for memoization
    long* mem = new long[n+1]; // +1 just to have nice recursion
    for(int i=0; i<=n; i++) mem[i] = -1;
    std::cout << endl << "Number of ways(recursion)     : " << waystoNstepsRec(n,mem);

    for(int i=0; i<=n; i++) mem[i] = -1; //clear array
    std::cout << endl << "Number of ways(dynamic prog)  : " << waystoNstepsDP(n,mem);

    std::cout << endl << "Number of ways(space O(3))    : " << waystoNstepsDPOpt(n);

    cout << endl;
    delete mem; //always have delete when you have 'new'
    return 0;
}
