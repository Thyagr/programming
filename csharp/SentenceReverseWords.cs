using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

public class Program
{
  public static void Main()
  {
    string s = "The fox jumped over the dog";
    s = ReverseWords(s);
    Console.WriteLine(s);
  }

  private static string ReverseWords(string sentence)
  {
    var stack = new Stack<string>();
    
    var words = sentence.Split(' ');
    foreach(var w in words)
    {
      stack.Push(w);
    }

    var sb = new StringBuilder();
    while(stack.Count > 0)
    {
      sb.Append($"{stack.Pop()} ");
    }
    return sb.ToString();
  }
}
