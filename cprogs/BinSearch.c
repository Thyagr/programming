# include <stdio.h>
# include <stdlib.h>

int swapType(int x, int y)
{
	return x > y ? 1 : 0; // change return value to change swap type
}

// having function pointer as parameter
void sortArray(int* A, int n, int (*swap_ptr)(int,int)) // using bubble sort here
{
	int i,j,temp;
	for (i =0; i< n; i++)
	{
		for (j =0; j < n-1 -i; j++)
		{
			if (swap_ptr(A[j],A[j+1])) //function call from its pointer
			{
				temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
			}
		}
	}
	printf("%s\n","Array has been sorted!");
}

int recBinSearch(int A[], int low, int high, int val)
{
	//printf("%d %d\n", low, high);
	if (low > high)
		return -1;
	int mid = low + (high-low)/2; // ... optimal ? maybe,  so high + low does not overflow
	if (A[mid] > val)
        return recBinSearch(A, low, mid - 1, val); // high = mid -1
	else if (A[mid] < val)
        return recBinSearch(A, mid + 1, high, val); // low = mid +1
	else
        return mid;
}

int iterBinSearch(int A[], int n, int val)
{
	int low = 0;
	int high = n-1;
	int mid;
	while (low <= high) // should be '<='
	{
		mid = (low + high)/2;
		if (val < A[mid]) high = mid - 1;
		else if (val > A[mid]) low = mid + 1;
		else return mid;
	}
	return -1;
}


int main (void)
{
	int n;
	int i;
	int val;

	printf("%s\n","Enter the number of elements in the array");
	scanf("%d",&n);
	int* Arr = (int*)malloc(n*sizeof(int)); // having typecast OK or not OK?

	printf("%s\n","Enter the values");
	for (i = 0; i < n; i++)
		scanf("%d",(Arr + i));

    /*int (*swap_ptr)(int,int)  = swapType; pointer to a function, so
    the call to it does not build up in stack*/

	sortArray(Arr, n, swapType);

	for (i = 0; i < n; i++)
		printf("%d ", *(Arr + i)); // print using pointers


	printf("\n%s\n", "Enter a value to search in the list: " );
	scanf("%d", &val);

	//i = recBinSearch(Arr, 0,n-1,val);
	i = iterBinSearch(Arr, n, val);

	if (i != -1)
		printf("%s %d %s %d \n", "The value ", Arr[i], "was found at position " , i+1);
	else
		printf("%s\n", "Value not in the array");

	return 0;
}
