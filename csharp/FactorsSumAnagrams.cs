using System;
using System.Collections.Generic;
using System.Linq;

public class Program
{
  private static HashSet<string> hashset = new HashSet<string>();
  public static void Main()
  {
    int n = int.MaxValue;
    var g = n.ToString();
    // FindFactors(n);
    // ReverseInt(n);

    
    //int[] arr = new int[] {2, 7, 1, 15, 11, 8, 9, -1, 0};
    // int sum = 9;
    // TwoSum(arr, sum); 
    
    /*
    *Anagrams
    var p_string = "abc";
    var p2_string = "bac";
    Permutations(p_string, 0, p_string.Length -1);
    if (hashset.Contains(p2_string))
    {
      Console.WriteLine($"{p_string} {p2_string} are anagrams");
    }*/
  }

  private static void FindFactors(int n)
  {
    var factors = new List<int>();
    for (int f = 1; f < Math.Sqrt(n); f++)
    {
      if (n % f == 0)
      {
        factors.Add(f);
        factors.Add(n/f);
      }
    }

    factors.ForEach(f => Console.WriteLine(f));
  }

  private static void ReverseInt(int n)
  {
    var n_s = n.ToString().ToCharArray();
    var st = 0;
    var ed = n_s.Length - 1;
    if (n_s[0] == '-') st = 1;

    while (st < ed)
    {
      var t = n_s[st];
      n_s[st] = n_s[ed];
      n_s[ed] = t;
      st++;
      ed--;
    }

    var s = new string(n_s);
    Console.WriteLine(s);
  }

  private static void TwoSum(int[] arr, int sum)
  {
    var hash = new HashSet<int>(arr);
    var tuples = new List<Tuple<int, int>>();
    foreach(var i in arr)
    {
      if (hash.Contains(sum - i))
      {
        tuples.Add(new Tuple<int, int>(i, sum -i));
        hash.Remove(i);
        hash.Remove(sum-i);
      }
    }

    tuples.ForEach(tup => Console.WriteLine($"{tup.Item1} {tup.Item2}"));
  }

  private static void Permutations(string s, int l, int r)
  {
    if (l == r) 
    {
      Console.WriteLine(s);
      hashset.Add(s);
      return;
    }

    for (int i = l; i <= r; i++)
    {
      s = SwapChars(s, i, l);   // swap i, l
      Permutations(s, l+1, r);  // recursively call permute
    }
  }

  private static string SwapChars(string str, int i, int j)
  {
    var carr = str.ToCharArray();
    var t = carr[i];
    carr[i] = carr[j];
    carr[j] = t;
    return new string(carr);
  }
}
