#include <iostream>
using namespace std;

//kadane algo, requires atleast 1 +ve num
void findmaxsumsubarray(int A[], int n)
{
    int sum = 0;
    int MaxSum = 0;
    int arrstart = 0;
    int arrend = 0;
    int s = 0;

    for (int i = 0; i < n; i++)
    {
        sum += A[i];
        if (sum > 0)
        {
            if (sum > MaxSum)
            {
                MaxSum = sum;
                arrstart = s;
                arrend = i;
            }
        }
        else
        {
            sum = 0;
            s = i + 1;
        }
    }
    cout << endl << "Max Sum : " << MaxSum << endl;
    cout << "Max Sub Array (start index - end index): " << arrstart << " - " << arrend << endl;
}

int main(void)
{
    int numelements;
    cout << "Enter # of elements: ";
    cin >> numelements;
    int* A = new int[numelements];
    for (int i=0; i<numelements; i++)
    {
        cout << "Element " << i + 1 << ": ";
        cin >> A[i];
    }
    findmaxsumsubarray(A, numelements);
    delete[] A; // deleting array
}
