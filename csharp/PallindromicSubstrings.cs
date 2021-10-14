using System;
using System.Collections.Generic;
using System.Linq;

public class Program
{
  public static void Main()
  {
    var str = "malayalamforgeeksskeegfor";
    var palString = Palindromic(str);
    Console.WriteLine(palinString);
  }

   private static string Palindromic(string s)
    {
        var palinString = string.Empty;
        for (int i = 0; i < s.Length; i++)
        {
          // start from entire string and work backwards 
          int j;
          // start from entire string and work backwards 
          for (j = len - i; j > 0; j--)
          {
            // Substring(startIndex, Length)
            if (IsPalindrome(s.Substring(i, j)))
              break;
          }

          //  if new substring is longer than previous
          if (palinString.Length < s.Substring(i, j).Length)
            palinString = s.Substring(i, j);
        }

        return palinString;
    }

    private static bool IsPalindrome(string str)
    {
        var rstr = new string(str.Reverse().ToArray());
        return string.Equals(str, rstr);
    }
}
