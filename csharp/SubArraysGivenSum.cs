using System;
using System.Collections.Generic;

public class Program
{
	public static void Main()
	{
		var arr = new int[]{5,0,5,10,3,2,-15,4};
		var sum = 5;
		SubArraysWithGivenSum_Optimal(arr, sum);
	}

	// O(n) solution
	private static void SubArraysWithGivenSum_Optimal(int[] arr, int sum)
	{
		int len = arr.Length;
		var prevSums = new Dictionary<int, int>();
		int subArrays = 0;
		int curSum = 0;

		for (int i = 0; i < len; i++)
		{
			curSum += arr[i];
            
			if (curSum == sum)
			    subArrays++;

			if (prevSums.ContainsKey(curSum - sum))
				subArrays += prevSums[curSum - sum];

			if (prevSums.ContainsKey(curSum))
				prevSums[curSum] += 1;
			else
				prevSums[curSum] = 1;
		}

		Console.WriteLine("SubArrays: " + subArrays);
	}
}