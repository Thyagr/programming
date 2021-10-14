using System;
using System.Collections.Generic;
using System.Linq;

public class Program
{
  public static void Main()
  {
    var arr = new int[] {12, 3, 4, 1, 6, 9, 6};
    int sum = 24;
    var list = ThreeSum(arr, sum);

    foreach(var l in list)
      Console.WriteLine($"{l.Item1} + {l.Item2} + {l.Item3} = {sum}");
  }

  private static List<(int, int, int)> ThreeSum(int[] arr, int sum)
  {
    var threeSum = new List<(int, int, int)>();
    int len = arr.Length;
    
    for (int i = 0; i < len; i++)
    {
      int newSum = sum - arr[i];

      // Basically DoubleSum from here
      var hash = new HashSet<int>();
      for (int j = i + 1; j < len; j++)
      {
        if (hash.Contains(newSum - arr[j]))
          threeSum.Add((arr[i], arr[j], newSum - arr[j]));
        else 
          hash.Add(arr[j]);
      }
    }
    
    return threeSum;
  }

  // twist on triple sum
  // sum of 2 nums = 3rd num
  // we can also sort the numbers and try differently
  private static List<(int, int, int)> Pythagorean(int[] arr)
  {
    var list = new List<(int, int, int)>();
    int len = arr.Length;
    // a2 + b2 = c2
    var sqarr = new int[len]; // or just compare squares
    for (int i = 0; i < len; i++)
    {
      sqarr[i] = arr[i] * arr[i];
    }
    
    for (int i = 0; i < len; i++) 
    {
      int sum = sqarr[i];
      var hash = new HashSet<int>();
      for (int j = 0; j < len; j++)
      {
        if (j == i) continue; // dont reuse same number
        if (hash.Contains(sum - sqarr[j]))
        {
          list.Add((sum, sum - sqarr[j], sqarr[j]));
        }
        else hash.Add(sqarr[j]);
      }
    }
    
    return  list;
  }
}
