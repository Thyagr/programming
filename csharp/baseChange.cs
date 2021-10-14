using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

public class Program
{
  private static readonly Dictionary<int, string> hex_map = new Dictionary<int, string> 
  {
    { 10, "A" },
    { 11, "B" },
    { 12, "C" },
    { 13, "D" },
    { 14, "E" },
    { 15, "F" },
  };

  private static void BaseRepresent(int num, int b, List<string> rep)
  {
    if (num >= b) 
      BaseRepresent(num/b, b, rep);
      
    var digit = num % b;
    if (digit > 9) 
      rep.Add(hex_map[digit]);
    else 
      rep.Add(digit.ToString());
  }

  private static string BaseConverter(int number, int b)
  {
    if (number < 0 || b < 0) 
    {
      return null;
    }

    var s = new StringBuilder();
    while (number > 0)
    {
      s.Append((number % b).ToString());
      number /= b;
    }

    return new string(s.ToString().Reverse().ToArray());
  }

  public static void Main()
  {
    int num = 100;
    int b = 16; // must be in range 1 - 16
    var representation = new List<string>();
    BaseRepresent(num, b, representation);
    Console.WriteLine(string.Join("", representation));

    var s = BaseConverter(num, b);
    Console.WriteLine(s);
  }

}
