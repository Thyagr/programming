#include <iostream>
using namespace std;

class poly
{
    private:
        int P[];
        int arrsize;
    public:
        poly();
        void derivative();

};

poly::poly()
{
    int i = 0;
    int an;
    cout << "Enter the polynomials a0 + a1x + a2x^2 + ......" << endl;
    do
    {
        cin >> an;
        if (cin.fail())
            break;
        else
            P[i++] = an;
    } while (1);
    arrsize = i;
    for (int k = 0; k< i; k++)
        cout << P[k] << "x^" << k << " + ";

}

void poly::derivative()
{

    cout << endl << "Derivative: ";
    for (int k = 1; k < arrsize; k++)
    {
        if ( P[k] !=0 )
            cout << P[k]*k << "x^" << k-1 << " + ";
    }

}

int main(void)
{
    poly pobj;
    pobj.derivative();
    return 0;
}
