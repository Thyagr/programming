using System;
using System.Collections.Generic;
using System.Linq;

public class Program
{
  public static void Main()
  {
    var arr = new int[] {4, 2, 3 , 2, 7};
    SplitArrayToEqualSum(arr);
    SplitArrayEqualSum(arr);
  }

  // method 1
  private static void SplitArrayToEqualSum(int[] arr)
  {
    int left = 0;
    int right = arr.Length - 1;

    int leftSum = arr[left];
    int rightSum = arr[right];
    while (left <= right)
    {
      if (leftSum < rightSum) 
      {
        left++;
        leftSum += arr[left];
      }
      else if (leftSum > rightSum)
      {
        right--;
        rightSum += arr[right];
      }
      else 
      {
        if (left == right - 1) break;
        left++;
        right--;
      }
    }

    if (leftSum == rightSum)
    {
      Console.WriteLine($"{left} {right}");
    }
  }

  // method 2 
  private static void SplitArrayEqualSum(int[] arr)
  {
    var sum = arr.Sum();
    var s = 0;
    for (int i = 0; i < arr.Length; i++)
    {
      s += arr[i];
      if (s == sum - s) 
      {
        Console.WriteLine($"Equal sum from index {i}");
        break;
      }
    }
  }
}
