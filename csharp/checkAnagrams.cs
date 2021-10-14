using System;
using System.Collections.Generic;
using System.Linq;

public class Program
{
  public static void Main()
  {
    var s1 = "abcdef";
    var s2 = "dabcff";
    var result =   Anagrams(s1, s2);
    Console.WriteLine(result);
  }

  private static bool Anagrams(string s1, string s2)
  {
    if (s1.Length != s2.Length) return false;

    // sorting method
    // var carr1 = s1.ToCharArray();
    // var carr2 = s2.ToCharArray();
    // Array.Sort(carr1);
    // Array.Sort(carr2);
    // return string.Equals(new string(carr1), new string(carr2));

    var dict1 = new Dictionary<char, int>();
    var dict2 = new Dictionary<char, int>();

    foreach (var c in s1)
    {
      if (dict1.ContainsKey(c)) dict1[c] += 1;
      else dict1[c] = 1;
    }

    foreach (var c in s2)
    {
      if (dict2.ContainsKey(c)) dict2[c] += 1;
      else dict2[c] = 1;
    }
	
	// compare collections
   if (dict1.Except(dict2).Any()) return false;
   else return true;
  }
}
