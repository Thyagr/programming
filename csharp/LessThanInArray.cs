using System;
using System.Collections.Generic;
using System.Linq;

public class Program
{
  public static void Main()
  {
    int[] arr = new int[] {1, 2, 4, 7, 15, 25, 30 };
    int num = 29;
    int less = Less_Than(arr, num);
    Console.WriteLine(less);
  }

  private static int Less_Than(int[] arr, int n)
  {
    Array.Sort(arr);
    int left = 0;
    int right = arr.Length - 1;
    int mid = 0;

    while (left <= right)
    {
      mid = (left + right)/2;
      // Console.WriteLine($"mid = {mid} -> {arr[mid]}");
      if (n < arr[mid]) right = mid - 1;
      else if (n > arr[mid]) left = mid + 1;
      else break;
    }

    if (arr[mid] >= n) return mid;
    else return mid + 1;
  }
}
