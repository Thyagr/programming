using System;
using System.Collections.Generic;
using System.Linq;

public class Program
{
  public static void Main()
  {
   var s = "pwwkew";
   Console.WriteLine(LongestSubstring(s));
  }

  private static string LongestSubstring(string s)
  {
    int len = s.Length;
    string substr = string.Empty;
    
    for (int i = 0; i < len; i++)
    {
      for (int j = len - i; j > 0; j--)
      {
        // (startindex, length) 
        var s2 = s.Substring(i, j);
        if (!IsCharRepeating(s2))
        {
          if (substr.Length < s2.Length)
            substr = s2;
          break;
        }
      }
    }

    return substr;
  }

  private static bool IsCharRepeating(string s)
  {
    var hash = new HashSet<char>(s.ToCharArray());
    return s.Length != hash.Count;
  }
}
