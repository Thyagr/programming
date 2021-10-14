using System;
using System.Collections.Generic;

public class Program
{
  public static void Main()
  {
    // var s = "aaabcccdeef";
    var s = "aaaa";
    var c = NonRepeating(s);

    if (c is null) Console.WriteLine("No non-repeating characters");
    else Console.WriteLine($"{c} is first non-repeating at index {s.IndexOf(c.ToString())}");
  }

  private static char? NonRepeating(string s)
  {
    var dict = new Dictionary<char, int>();

    foreach (var c in s)
    {
      if (dict.ContainsKey(c)) dict[c] += 1;
      else dict[c] = 1;
    }

    foreach (var c in s)
    {
      if (dict[c] == 1) return c;
    }

    return null;
  }
}
