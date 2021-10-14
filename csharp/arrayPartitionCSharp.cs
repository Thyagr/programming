using System;
using System.Collections.Generic;
using System.Linq;

public class Program
{
  public static void Main()
  {
    var rnd = new Random();
    const int len = 10;
    int[] arr = new int[len];
    for (int i = 0; i < len; i++)
    {
      arr[i] = rnd.Next(1, 100);
    }
    PrintArr(arr);
    Partition(arr);
    PrintArr(arr);
  }

   // partition into odd and even
  private static void Partition(int[] arr)
  {
    int l = 0, r = arr.Length - 1;

    while (l < r)
    {
      if (arr[l] % 2 == 0)
      {
        Swap(arr, l, r);
        r -= 1;
      }
      else
      {
        l += 1;
      }
    }
  }

  private static void Swap(int[] arr, int i, int j)
  {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }

  private static void PrintArr(int[] arr)
  {
    foreach (var i in arr)
    {
      Console.Write($"{i} ");
    }
    Console.WriteLine();
  }
  
}
