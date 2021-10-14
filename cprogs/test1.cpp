#include <iostream>
#include <stdio.h>
using namespace std;

bool binsearch(int A[], int len, int num)
{
	int l = 0;
	int h = len;
	while (l < h)
	{
		int mid = (l + h)/2;
		if (A[mid] == num) return true;
		else if (A[mid] > num) h = mid - 1;
		else l = mid + 1;
	}

return false;
}

int main(void)
{
	int num;
	char* str = "Hello";
	printf("%s World",str);
	int A[] = {2,5,7,8,9,134,424,535};


	cout << endl << A;
	cout << "Enter a number: ";
	cin >> num;
	cout << endl;
	bool result  = binsearch(A,7,num);
	result ? cout << "True" : cout << "False";
	return 0;
}
