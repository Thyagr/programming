using System;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;

public class Program
{
  public static void Main()
  {
    var s = @"11as23p38974y01i ow3h4p23   2\43289r980y3p89032u90230";

    // var n = AllNumbers2(s);
    // Array.ForEach(n, i => Console.Write($"{i} "));

    var nums = AllNumbers(s);
    Array.ForEach(nums, i => Console.Write($"{i} "));
  }

  private static int[] AllNumbers(string s)
  {
    
    const string pattern = @"(\d+)";
    var regex = new Regex(pattern);

    var matches = regex.Matches(s);
    var list = new List<int>(); // use list over hashset to preserve order
    for (int c = 0; c < matches.Count; c++)
    {
      list.Add(int.Parse(matches[c].Value.ToString()));
      // Console.WriteLine(matches[c].Value);
    }

    return list.Distinct().ToArray();
  }

  private static int[] AllNumbers2(string s)
  {
   var hash = new HashSet<int>();
   var numbers = new HashSet<char> { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };

   foreach (var c in s)
   {
     if (numbers.Contains(c))
     {
       hash.Add(Convert.ToInt32(c.ToString()));
     } 
   }

   return hash.ToArray();
  }
}
