#include <iostream>
using namespace std;

int rotatedarray(int arr[], int n)
{
	int high = n;
	int low = 0;
	int mid = -1;

	while (low < high)
	{
		mid = (high + low) / 2;
		if (arr[mid] < arr[low]) high = mid - 1;
		else low = mid + 1;
	}
	return mid;
}

int main(void)
{
	int len = 0;
	cout << "Enter # of elements: ";
	cin >> len;
	int* arr = new int[len - 1];
	cout << endl << "Rotated array" << endl;
	for (int i = 0; i<len; i++)
	{
		cout << "Enter element " << i + 1 << ": ";
		cin >> arr[i];
	}

	int pos = rotatedarray(arr, len - 1);
	cout << pos;
	cin.get();

	return 0;
}

