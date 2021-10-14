using System;

public class Program
{
  private static void MaxSubArray(int[] arr)
  {
    int len = arr.Length;
    int max = 0;
    int sum = 0;
    int startIndex = 0, endIndex = 0, s = 0;
    for (int i = 0; i < len; i++)
    {
      sum += arr[i];
      if (sum > 0)
      {
        if (sum > max)
        {
          max = sum;
          startIndex = s;
          endIndex = i;
        }
      }
      else
      {
        sum = 0;
        s = i + 1;
      }
    }

    Console.WriteLine("Max sum = " + max);
    Console.WriteLine($"Start index = {startIndex}[{arr[startIndex]}]  End index = {endIndex}[{arr[endIndex]}]");
  }

  public static void Main()
  {
    int len = 10;
    var arr = new int[len]; 
    var rand = new Random();
    for (int i = 0; i < len; i++)
    {
      arr[i] = rand.Next(-9, 9);
      Console.Write(arr[i] + " ");
    }
    Console.WriteLine();

    // var arr = new int[] {-2, -3, 4, -1, -2, 1, 5, -3};
    MaxSubArray(arr);
  }

}
