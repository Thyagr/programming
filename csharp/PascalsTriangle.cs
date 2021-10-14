using System;

public class Program
{
  public static void Main()
  {
    int k = 3;
    PascalTriangle(k);
  }

  private static void PascalTriangle(int k)
  {
    int[] row1 = new int[] { 1 };

    for (int i = 1; i <= k; i++)
    {
      var row2 = new int[i + 1];
      row2[0] = 1; // mark ends with 1
      row2[i] = 1;

      for (int j = 1; j < row1.Length; j++)
      {
        row2[j] = row1[j - 1] + row1[j];
      }

      Array.ForEach(row2, n => Console.Write(n + " "));
      Console.WriteLine();
      row1 = row2;
    }
  }
}
