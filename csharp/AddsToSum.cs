using System;
using System.Collections.Generic;
using System.Linq;

public class Program
{
  public static void Main()
  {
    var arr = new int[] { 1, 2, 3, 6, 7 , 8 };
    int sum = 10;
    var list = AddsToSum(arr, sum);

    foreach (var (x, y) in list)
    {
      Console.WriteLine($"{x} + {y} = {sum}");
    }

    Console.WriteLine("Double sum with sorted array");
		DoubleSum2(arr, sum);
  }

  private static List<(int, int)> DoubleSum(int[] arr, int sum)
  {
    var hash = new HashSet<int>();
    var list = new List<(int, int)>();
   
    foreach(var i in arr)
    {
      var j = sum - i;
      if (hash.Contains(j))
        list.Add((i, j));
      else 
        hash.Add(i);
    }

    return list;
  }

  private static IEnumerable<(int, int)> AddsToSum(int[] arr, int sum)
  {
    var hash = new HashSet<int>(arr);
    var list = new List<(int, int)>();
    foreach (var item in arr.Distinct())
    {
      if (hash.Contains(sum - item))
      {
        list.Add((item, sum - item));
        hash.Remove(item); // so same pair not repeated 
      }
    }

    return list;
  }

  private static void DoubleSum2(int[] arr, int sum)
  {
    Array.Sort(arr); // this changes the array
    int left = 0;
    int right = arr.Length - 1;
    var list = new List<(int, int)>();
    
    while (left <= right)
    {
      int s = arr[left] + arr[right];

      if (s > sum) 
        right--;
      else if (s < sum) 
        left++;
      else 
      {
        list.Add((arr[left], arr[right]));
        left++;
        right--;
      }
    }
    
    list.ForEach(l => Console.WriteLine($"{l.Item1} + {l.Item2} = {sum}"));
  }
}
