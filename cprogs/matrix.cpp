#include <iostream>

using namespace std;

class MatrixOps
{
private:
    int rows;
    int cols;
    int** mat;
    //int* M1[];

public:
    MatrixOps(int, int);
    ~MatrixOps();
    void InputMatrix();
    void PrintMatrix();
    void ListDiagonals();
};

MatrixOps::MatrixOps(int r, int c)
{
    if (r > 0 && c >0)
    {
        rows = r;
        cols = c;
        mat = new int*[rows];
        for (int p=0; p<rows; p++)
            mat[p] = new int[cols];
    }
    else
    {
        cout << endl << "Invalid numbers ";
    }
}

MatrixOps::~MatrixOps()
{
    for (int p=0; p<cols; p++)
        delete [] mat[p];
    delete [] mat;
}

void MatrixOps::InputMatrix()
{
    /*
    // better memory mgmt + efficient
    M = new int[rows*cols];
    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<cols; j++)
            {
                cout << "Enter mat[" << i << "]" << "[" << j << "]: ";
                cin >> mat[i*cols+ j];
            }

    }
    */
    for (int i=0;i<rows;i++)
    {
        for (int j=0; j<cols; j++)
        {
            cout << "Enter mat[" << i << "]" << "[" << j << "]: ";
            cin >> mat[i][j];
        }
    }

}

void MatrixOps::PrintMatrix()
{
    cout << endl << "Rows: " << rows << " Cols: " << cols << endl;
    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<cols; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

void MatrixOps::ListDiagonals()
{
    cout << endl << "Main Diagonal: ";
    for (int p=0; p<rows; p++)
        cout << mat[p][p] << " ";
}

int main(int argc, char* argv[])
{
    int r, c;
    cout << "Matrix Operations" << endl;

    cout << "Enter # of rows: ";
    cin >> r;

    cout << "Enter # of columns: ";
    cin >> c;

    MatrixOps Mat (r,c);
    Mat.InputMatrix();
    Mat.PrintMatrix();
    Mat.ListDiagonals();

    return 0;
}
