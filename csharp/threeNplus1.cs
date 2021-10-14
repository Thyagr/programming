using System;
using System.Collections.Generic;
using System.Linq;

public class Program
{
  public static void Main()
  {
    ulong n = 18443751615;
    var list = ThreeNPlus1(n);

    ulong max = 0;
    int count = 0;
    foreach (var item in list)
    {
      count += 1;
      if (item > max) max = item;
      // Console.Write(item + " ");
    }
    Console.WriteLine($"\nSteps = {count} Max value: {max}");
  }

  private static IEnumerable<ulong> ThreeNPlus1(ulong n)
  {
    var list = new List<ulong> { n };

    while (n != 1)
    {
      if (n%2 == 0) n = n/2;
      else n = 3*n + 1;
      list.Add(n);
    }

    return list;
  }
}
