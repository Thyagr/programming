using System;
using System.Collections.Generic;
using System.Linq;

public class Program
{
  private static Dictionary<char, char> BracketPairs = new Dictionary<char, char>()
  {
    {'[', ']'},
    {'(', ')'},
    {'{', '}'},
  };

  public static void Main()
  {
    var bracketStr = "{{[[(())]]}}";
    var b = Balanced(bracketStr);
    Console.WriteLine(b);
  }

  private static bool Balanced(string bracketStr)
  {
    var stack = new Stack<char>(bracketStr.Length);

    foreach (var bracket in bracketStr)
    {
      if (BracketPairs.ContainsKey(bracket)) 
      {
        // push opening bracket
        stack.Push(bracket);
      }
      else
      {
        // check before pop
        if (stack.Count == 0) return false;
        var top = stack.Pop();

        // check if opening = closing
        if (BracketPairs[top] != bracket)
          return false;
      }
    }

    // ensure stack is empty after all pops
    return stack.Count == 0;
  }
}
