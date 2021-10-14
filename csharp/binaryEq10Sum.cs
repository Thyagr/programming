using System;
using System.Collections.Generic;

public class Program
{
  public static void Main()
  {
    /* (Similar to balanced brackets)
    Find all binary numbers of given length that have equal 1,0 
    and then find their sum
    */
    var N = 3; // len/2
    var carr = new char[2*N];
    var binary = new HashSet<string>();

    Print10Permutations(carr, N, N, 0, binary);
    var sum = 0;
    foreach (var b in binary)
    {
      int i = Convert.ToInt32(b, 2);
      sum += i;
      Console.WriteLine(b + " - " + i);
    }

    Console.WriteLine("Sum: " + sum);
  }

  private static void Print10Permutations(char[] carr, int leftRem, int RightRem, int count, HashSet<string> binary)
  {
    // if we want only 1 followed by 0, use leftRem > RightRem to return
    if (leftRem < 0 || RightRem < 0) return;

    if (leftRem == 0 && RightRem == 0)
    {
      binary.Add(new string(carr));
    }

    if (leftRem > 0)
    {
      carr[count] = '1';
      Print10Permutations(carr, leftRem - 1, RightRem, count + 1, binary);
    }

    if (RightRem > 0)
    {
      carr[count] = '0';
      Print10Permutations(carr, leftRem, RightRem -1, count + 1, binary);
    }
  }
}
