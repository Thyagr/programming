using System;
using System.Collections.Generic;

public class Program
{
  public static void Main()
  {
    int n = 507044212;
    var s = BigConsecutive(n);
    Console.WriteLine("Max consecutive sum = " + s);
  }

  private static int BigConsecutive(int num)
  {
    if (num == 0) return 0;

    var list = new List<int>();
    while (num > 0)
    {
      list.Add(num % 10);
      num /= 10;
    }

    int sum = 0;
    for (int i = 0; i < list.Count - 1; i++)
    {
      int s = list[i] + list[i+1];
      if (s > sum)
      {
        sum = s;
      }
    }

    return sum;
  }
}
