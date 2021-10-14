using System;

public class Program
{
  public static void Main()
  {
    int[] arr = new int[] { 10, 20, 5, 15, 25 };
    var prefixArray = PrefixSumArray(arr);
    Array.ForEach(prefixArray, i => Console.Write(i + " "));
  }

  private static int[] PrefixSumArray(int[] arr)
  {
    int len = arr.Length;
    var prefixArray = new int[len];

    prefixArray[0] = arr[0];
    for (int i = 1; i < len; i++)
    {
      prefixArray[i] = prefixArray[i - 1] + arr[i];
    }

    return prefixArray;
  }
}
