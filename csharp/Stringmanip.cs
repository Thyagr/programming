using System;
using System.Collections.Generic;
using System.Linq;

public class Program
{
  public static void Main()
  {
    string s = "312345abcD";
    var c = s.ToCharArray().Reverse();
    Console.WriteLine(string.Join(string.Empty, c));
    s = s.ToUpper();
    Console.WriteLine(s);
    s = s.ToLower();
    Console.WriteLine(s);

    int sum = 0;
    foreach (var q in s)
    {
      if (char.IsDigit(q))
      {
        sum += int.Parse(q.ToString());
      }
    }
    Console.WriteLine(sum);

    uint n2 = 32;
    uint b2 = 2;
    byte n1 = 10;
    int b1 = int.Parse(b2.ToString());
    // var ns = Convert.ToString(n1, toBase: b1);
    // Console.WriteLine(ns);
    var ns = BaseReperesentation(n2, b2);
    Console.WriteLine(ns);

    var s2 ="abbbcdeffgabceeddeadbc";
    s2 = RemoveDuplicateChars(s2);
    Console.WriteLine(s2);
  }

  private static string BaseReperesentation(uint num, uint b)
  {
    string num_s = string.Empty;
    if (num == 0) return "0";
    while (num > 0)
    {
      uint d = num % b;
      num_s += d.ToString();
      num = num/b;
    }

    return new string(num_s.Reverse().ToArray());
  }

  private static string RemoveDuplicateChars(string s)
  {
    var hash = new HashSet<char>(s.ToCharArray());

    // foreach(var c in s)
    // {
    //   hash.Add(c);
    // }

    return new string(hash.ToArray()); // order not guaranteed
  }
}
