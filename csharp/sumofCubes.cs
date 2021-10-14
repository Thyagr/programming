using System;
using System.Collections.Generic;
using System.Linq;

public class Program
{
  public static void Main()
  {
    /*
    find all
    a3 + b3 = c3 + d3
    */
    int range = 30;
    // generate a dictionary of int, int with all cubes 
    var dict = Cubes(range);

    // compute formula 
    int count = 0;
    var hash = new HashSet<int>();
    for(int a = 1; a <= range; a++)
    {
       for(int b = 1; b <= range; b++)
       {
          for(int c = 1; c <= range; c++)
          {
            for(int d = 1; d <= range; d++)
            {
              if ((a+b+c+d)%2 == 0 
                    && (a+b) != (c+d)
                    && (hashCount(hash, a, b, c, d) <= 2)
                  )
              {
                var a3 = dict[a];
                var b3 = dict[b];
                var c3 = dict[c];
                var d3 = dict[d];

                if (a3 + b3 == c3 + d3)
                {
                  count += 1;
                  hash.Add(a); hash.Add(b); hash.Add(c); hash.Add(d);
                  Console.WriteLine($"{a3} + {b3} = {c3} + {d3}");
                }
              }
            }
          }
       }
    }
    Console.WriteLine(count);
  }

  private static Dictionary<int, int> Cubes(int range)
  {
    var dict = new Dictionary<int, int>();
    for (int i = 1; i <= range; i++)
    {
      dict.Add(i, i*i*i);
    }
    // dict.ToList().ForEach(d => Console.WriteLine($"{d.Key}: {d.Value}"));
    return dict;
  }

  private static int hashCount(HashSet<int> hash, int a, int b, int c, int d)
  {
    int result =  Convert.ToInt32(hash.Contains(a)) + Convert.ToInt32(hash.Contains(b)) 
                    + Convert.ToInt32(hash.Contains(c)) + Convert.ToInt32(hash.Contains(d));
    return result;
  }
}
