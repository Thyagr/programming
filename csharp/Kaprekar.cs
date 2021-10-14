using System;
using System.Collections.Generic;
using System.Linq;

// https://en.wikipedia.org/wiki/6174_(number) - Kaprekar constant
public class Program
{
  public static void Main()
  {
    int n = 1213;
    var hash = new HashSet<int>();
    int k = Kaprekar(n, hash, n.ToString().Length);
    Console.WriteLine($"Kaprekar of {n} = {k}");

    int ki = Kaprekar_Iterative(n);
    Console.WriteLine($"Kaprekar (iterative) of {n} = {k}");
  }

  private static int Kaprekar(int number, HashSet<int> hash, int len)
  {
    if (hash.Contains(number)) 
    {
      return number;
    }
    
    hash.Add(number);

    // int -> string -> list -> sort -> string -> int
    var digits = new List<char>(number.ToString());
    digits.Sort((a, b) => b.CompareTo(a)); // sort descending
      
    var u = new string(digits.ToArray());
    if (u.Length < len) u += "0";   // pad zero for bigger number
      
    digits.Reverse();
    var v = new string(digits.ToArray());
	
	  // bigger number - smaller number
    var w = int.Parse(u) - int.Parse(v);
    Console.WriteLine($"{u} - {v} = {w}");

    return Kaprekar(w, hash, len); // recursively call function              
  }

  private static int Kaprekar_Iterative(int number)
  {
    var hash = new HashSet<int>();
    int len = number.ToString().Length;

    while (!hash.Contains(number))
    {
      hash.Add(number);

      var digits = new List<char>(number.ToString());
      digits.Sort((a, b) => b.CompareTo(a));
        
      var u = new string(digits.ToArray());
      if (u.Length < len) 
      {
        string.Concat(u, "0");
      }

      digits.Reverse();
      var v = new string(digits.ToArray());
    
      number = int.Parse(u) - int.Parse(v);
      Console.WriteLine($"{u} - {v} = {number}");
    }

    return number;
  }
}
