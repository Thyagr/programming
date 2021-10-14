using System;
using System.Collections.Generic;
using System.Linq;

public class Program
{
  public static void Main()
  {
    string num1 = "902873987923";
    string num2 = "2342412222344";

    var sum = AddNumbers(num1, num2);
    Console.WriteLine($"{num1} + {num2} = {sum}");
  }

  private static string AddNumbers(string num1, string num2)
  {
    int len1 = num1.Length;
    int len2 = num2.Length;
    string n1, n2;

    if (len1 > len2) // find longer string
    {
      n1 = ReverseString(num1);
      n2 = ReverseString(num2);
    }
    else
    {
      n1 = ReverseString(num2);
      n2 = ReverseString(num1);
    }
    int carry = 0;
    string sum = string.Empty;

    for (int i = 0; i < n2.Length; i++)
    {
      int d1 = int.Parse(n1[i].ToString());
      int d2 = int.Parse(n2[i].ToString());

      int d = (d1 + d2 + carry) % 10;
      carry = (d1 + d2 + carry) / 10;
      sum += d;
    }
    for (int i = n2.Length; i < n1.Length; i++)
    {
      int d1 = int.Parse(n1[i].ToString());
      int d = (d1 + carry) % 10;
      carry = (d1 + carry) / 10;
      sum += d;
    }

    if (carry > 0) sum += carry; // final carry
    return ReverseString(sum);
  }

  private static string ReverseString(string s)
  {
    var carr = s.ToCharArray();
    Array.Reverse(carr);
    return new string(carr);
  }
}
