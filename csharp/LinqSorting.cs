using System;
using System.Collections.Generic;
using System.Linq;

public class Program
{
  public static void Main()
  {
    var tuplesArr = new (int,int)[] {  (1, 5), (3, 7), (4, 6), (6, 8) };
    var intervals = tuplesArr.ToList();
    // sort by first elem in inc order (swap p, q for dec order)
    intervals.Sort((p, q) => p.Item1.CompareTo(q.Item1));
    // use firt.Item1 and last.Item2 to get the final answer
    intervals.ForEach(x => Console.WriteLine($"({x.Item1} {x.Item2})"));

    var str = "this is going to be a very good day";
    StringToDict(str, out var d);

    // use x.Key to sort by Keys
    d = d.OrderBy(x => x.Value).Reverse().ToDictionary(x => x.Key, x => x.Value);
    foreach (var kvp in d)
    {
      Console.WriteLine($"{kvp.Key} : {kvp.Value}");
    }  
  }

  private static void StringToDict(string s, out Dictionary<char, int> dict)
  {
    dict = new Dictionary<char, int>();
    
    foreach (var c in s)
    {
      if (c == ' ') continue;
      if (dict.ContainsKey(c)) dict[c] += 1;
      else dict[c] = 1;
    }
  }
}
