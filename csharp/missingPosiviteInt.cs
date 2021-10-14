using System;
using System.Collections.Generic;
using System.Linq;

public class Program
{
  public static void Main()
  {
    int[] numbers = { 2,3,4,-1,1,5,7 };
    /*
    For arrays in CSharp
    Array.Sort(numbers); // sorting 
    Array.Reverse(numbers) // reversing
    Array.ForEach<int>(numbers, n => Console.Write($"{n} ")); // enumerating
    */
    // [1,2,0]
    // [-8, -7, -6]
    int m = MissingInt(numbers);
    Console.WriteLine($"Missing +ve int: {m}");
  }

  private static int MissingInt(int[] arr)
  {
    int count = 0;
    int sum = 0;
    int max = arr[0];
    foreach (var n in arr)
    {
      if (n > 0) 
      {
        sum += n;
        count++;
        if (n > max) max = n;
      }
    }

    int expected = count*(count+1)/2;
    if (count == 0) return 1;
    else if (sum == expected) return max + 1;
    else
    {
      expected = (count+2)*(count+1)/2;
      return expected - sum;
    } 
  }
}
