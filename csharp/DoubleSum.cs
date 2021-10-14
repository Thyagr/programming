using System;
using System.Collections.Generic;
using System.Linq;

public class Program
{
  public static void Main()
  {
    int[] arr = new int[] {12, 3, 4, 1, 6, 9, 6};
    int sum = 15;

    var doubleSum = DoubleSum(arr, sum);
    doubleSum.ForEach(d => Console.WriteLine($"{d.Item1} + {d.Item2} = {sum}"));

    Console.WriteLine("For a sorted list");
    Array.Sort(arr);
    var doubleSumSorted = DoubleSumSorted(arr, sum);
    doubleSumSorted.ForEach(d => Console.WriteLine($"{d.Item1} + {d.Item2} = {sum}"));
  }

  private static List<(int, int)> DoubleSum(int[] arr, int sum)
  {
    var hash = new HashSet<int>();
    var list = new List<(int, int)>();
   
    foreach(var i in arr)
    {
      if (hash.Contains(sum - i))
        list.Add((i, sum - i));
      else 
        hash.Add(i);
    }

    return list;
  }

  private static List<(int, int)> DoubleSumSorted(int[] arr, int sum)
  {
    int len = arr.Length;
    int left = 0; 
    int right = len - 1;
    var list = new List<(int, int)>();

    while (left < right)
    {
      var s = arr[left] + arr[right];
      if (s > sum) right -= 1;
      else if (s < sum) left += 1;
      else {
        list.Add((arr[left], arr[right]));
        // so that it does not go into infinite and search for others
        left += 1;
        right -= 1;
      }
    }

    return list;
  }
}
