#include <iostream>
using namespace std;
#include <stack>
#include <queue>
#include <unordered_map>

#define ArrSize 10

class Node
{
public:
int x;
int A[ArrSize];
Node* ptr;
};

void printstr(string& x)
{
    cout << endl << x << x.length() ;
    for (int k =0; k < x.length(); k++)
        x[k] ^= ' ';
    x = x + " bye";
}

int main()
{
Node* head = new Node;
head ->x = 10;
head->ptr = NULL;

std::queue<int> Q;
std::stack<int> S;
std::unordered_map<int,int> umap;

for (int i=0; i< ArrSize; i++)
{
head->A[i] = i+2;
Q.push(head->A[i]);
S.push(i+2);
}

for (int j = 0; j< ArrSize; j++)
{
cout << head->A[j] << " " << Q.front() << " " << S.top() << endl;
Q.pop();
S.pop();
}

string mystr = "Hello there ";
printstr(mystr);
cout << endl << mystr;
delete head;

return 0;
}

