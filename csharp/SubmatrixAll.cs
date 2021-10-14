// C# program to implement
// the above approach
using System;
public class GFG
{
// Function to find maximum sum submatrix O(N^6)
static void maxSubmatrixSum(int[,] matrix)
{

	// Stores the number of rows
	// and columns in the matrix
	int r = matrix.GetLength(0);
	int c = matrix.GetLength(1);

	// Stores maximum submatrix sum
	int maxSubmatrix = 0;

	// Take each row as starting row
	for (int i = 0; i < r; i++) {

		// Take each column as the
		// starting column
		for (int j = 0; j < c; j++) {

			// Take each row as the
			// ending row
			for (int k = i; k < r; k++) {

				// Take each column as
				// the ending column
				for (int l = j; l < c; l++) {

					// Stores the sum of submatrix
					// having topleft index(i, j)
					// and bottom right index (k, l)
					int sumSubmatrix = 0;

					// Iterate the submatrix
					// row-wise and calculate its sum
					for (int m = i; m <= k; m++) {
						for (int n = j; n <= l; n++) {
							sumSubmatrix += matrix[m, n];
						}
					}

					// Update the maximum sum
					maxSubmatrix= Math.Max(maxSubmatrix,sumSubmatrix);
				}
			}
		}
	}

	// Print the answer
	Console.WriteLine(maxSubmatrix);
}

// Driver Code
public static void Main(String []args)
{
	int[,] matrix = { { 0, -2, -7, 0 },
						{ 9, 2, -6, 2 },
						{ -4, 1, -4, 1 },
						{ -1, 8, 0, -2 } };

	maxSubmatrixSum(matrix);
}
}

// This code is contributed by sanjoy_62.
