using System;
using System.Collections.Generic;
using System.Linq;

public class Program
{
  public static void Main()
  {
    var intervals = new List<(int, int)> { (6,8), (1,5), (2,4), (4,9) };  
    var (a, b) = MergeOverlappingIntervals(intervals);
    Console.WriteLine($"Overlapping interval: [{a}, {b}]");
  }

  private static (int, int) MergeOverlappingIntervals(List<(int, int)> intervals)
  {
    // sort by first elem in inc order (swap p, q for dec order)
    intervals.Sort( (p, q) => p.Item1.CompareTo(q.Item1) );
    // intervals.ForEach(x => Console.WriteLine($"({x.Item1} {x.Item2})"));

    int left = int.MaxValue;
    int right = int.MinValue;

    foreach (var (x, y) in intervals)
    {
      if (x < left) left = x;
      if (y > right) right = y;
    }

    return (left, right);
  }
}
