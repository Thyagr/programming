using System;
using System.Collections.Generic;
using System.Linq;

public class Program
{
  public static void Main()
  {
    var path = "/home/foo/../.";
    var result = SimplifyPath(path);
    Console.WriteLine(result);
  }

  private static string SimplifyPath(string path)
  {
    string result = string.Empty;
    var stack = new Stack<string>();

    path.TrimEnd('/'); 
    path.TrimStart('/');

    var dirs = path.Split('/');
    foreach (var d in dirs)
    {
      /* eliminates '//' etc  */
      if (string.IsNullOrEmpty(d)) continue;

      if (d == ".") continue;
      else if (d == ".." && stack.Count > 0) stack.Pop();
      else if (!string.Equals(d, "..")) stack.Push(d);
    }

    /* if reverse is not available
    var s3 = new string[stack.Count];
    for (int i = stack.Count - 1; i >=0; i--)
    {
      s3[i] = stack.Pop();
    }

    result = string.Join("/", s3);
    return '/' + result;
    */

    foreach (var s in stack.Reverse())
    {
      result += ('/' + s);
    }

    return result;
  }
}
