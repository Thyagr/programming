using System;

public class Program
{
  public static void Main()
  {
    var strs = new string[] { "flower","flow","flight" };
    var prefix = LongestPrefix(strs);
    Console.WriteLine(prefix);
  }

  private static string LongestPrefix(string[] arr)
  {
    if (arr.Length == 0) return string.Empty;
    if (arr.Length == 1) return arr[0];

    string prefix = string.Empty;
    int minLen = 0;
    
    foreach (var s in arr)
    {
      if (minLen < s.Length) minLen = s.Length;
    }

    for (int i = 0; i < minLen; i++)
    {
      var c = arr[0][i];
      bool flag = true;
      for (int j = 1; j < arr.Length; j++)
      {
        if (arr[j][i] != c) 
        {
          flag = false;
          break;
        }
      }
      if (flag == false) break;
      else prefix += c; 
    }

    return prefix;
  }
}
