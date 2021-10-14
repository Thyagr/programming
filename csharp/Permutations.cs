using System;
using System.Collections.Generic;

public class Program
{
  public static void Main()
  {
    string s = "123";
    int len = s.Length;

    var perms = new List<string>(len);
    Perumutations(s, 0, len-1, perms);

    foreach (var p in perms)
    {
      Console.WriteLine(p);
    }
  }

  private static void Perumutations(string s, int l, int r, List<string> perms)
  {
    if (l == r) perms.Add(s);
    else 
    {
      for (int i = l; i <= r; i++)
      {
        s = SwapChars(s, l, i);
        Perumutations(s, l+1, r, perms);
      }
    }
  }

  private static string SwapChars(string s, int l, int i)
  {
    var carr = s.ToCharArray();
    var t = carr[l];
    carr[l] = carr[i];
    carr[i] = t;
    return new string(carr);
  }
}
