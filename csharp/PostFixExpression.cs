using System;
using System.Collections.Generic;
using System.Linq;

public class Program
{
  public static void Main()
  {
    string[] exp = new string[] { "12", "32", "1", "*", "+", "9", "-" };
    int result = Postfix_Evaluate(exp);
    Console.WriteLine(result);
  }

  private static int Postfix_Evaluate(string[] expression)
  {
    int result = 0;
    bool divideByZero = false;
    bool invalidExpression = false;
    var stack = new Stack<int>();
    var operands = new HashSet<string> { "+", "-", "*", "/" };

    foreach (var e in expression)
    {
      if (!operands.Contains(e)) 
      {
        stack.Push(int.Parse(e));
      }
      else if (int.TryParse(e, out _)) // check for non-digits
      {
        invalidExpression = true;
        break;
      }
      else
      {
        int a = stack.Pop();
        int b = stack.Pop();
        switch (e)
        {
          case "+":
            stack.Push(b + a);
            break;
          case "-":
            stack.Push(b - a);
            break;
          case "*":
            stack.Push(b * a);
            break;
          case "/":
            if (a != 0) stack.Push(b / a);
            else divideByZero = true;
            break;
        }
        if (divideByZero) break;
      }
    }

    if (divideByZero) Console.WriteLine("Divide by zero error");
    else if (invalidExpression || stack.Count != 1) Console.WriteLine("Invalid expression");
    else result = stack.Pop(); 
    
    return result;
  }
}
