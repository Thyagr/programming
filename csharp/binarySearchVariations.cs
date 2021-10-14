using System;
using System.Collections.Generic;
using System.Linq;

public class Program
{
  public static void Main()
  {
    var arr = new int[] {1, 1, 1, 2, 2, 2, 2, 2, 3, 5};
    int val = 4;
    var limits = BinsearchLimits(arr, val);

    Console.WriteLine($"{limits.Item1}, {limits.Item2}");

    /*
    Query array
    var arr = new int[] { 1, 5, 2, 8, 3 };
    Array.Sort(arr);
    var Q = new int[] { 1, 4, 9};
    var range_arr = new int[Q.Length];
    int i = 0;
    foreach (var q in Q)
    {
        range_arr[i] = FindRange(arr, Q[i]);
      i++;
    }
    Array.ForEach(range_arr, i => Console.Write(i + " "));
    */
  }

  private static (int, int) BinsearchLimits(int[] arr, int value)
  {
    // values are repeated multiple times 
    int left = 0;
    int right = arr.Length -1;
    var limits = (-1, -1);
    // search for left
    while (left <= right)
    {
      int mid = (left + right)/2;

      if (arr[mid] >= value) right = mid - 1; // keep moving ?
      if (arr[mid] < value) left = mid + 1;
    }

    if (arr[left] == value)
      limits.Item1 = left;
	  
    // reset left and right
	  left = 0;
    right = arr.Length -1;

	  // search for right limit
    while (left <= right)
    {
      int mid = (left + right)/2;

      if (arr[mid] > value) right = mid - 1; 
      if (arr[mid] <= value) left = mid + 1; // keep moving ?
    }
	  
    if (arr[right] == value)
      limits.Item2 = right;

    return limits;
  }

  private static int FindRange(int[] arr, int n)
  {
    // find elements <= to a given number in an array
    int len = arr.Length;

    int left = 0;
    int right = len - 1;
    int res = 0;

    while (left <= right)
    {
      int mid = (left + right)/2;
      if (n < arr[mid]) right = mid - 1;
      else if (n > arr[mid]) left = mid + 1;
      else 
      {
        res = mid;
        break;
      }
    }

    if (left > right) return left;
    else if (res > 0) return res;
    else return 0;
  }
}
