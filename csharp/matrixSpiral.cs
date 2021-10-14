using System;
using System.Collections.Generic;
using System.Linq;

public class Program
{
  public static void Main()
  {
    var matrix =  new int[,]{ {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    PrintMatrix(matrix);
    // Console.WriteLine();
    // MaxEqualRowsAfterFlips(matrix);
    // PrintMatrix(matrix);
    // Console.WriteLine();
    // PrintMatrix(Transpose(matrix));
    // var arr = GetColumn(matrix, 2);
    // Array.ForEach(arr, i => Console.Write($"{i} "));
    // Console.WriteLine();
    // arr = GetRow(matrix, 1);
    // Array.ForEach(arr, i => Console.Write($"{i} "));

    var spiral = SpiralOrder(matrix);
    spiral.ForEach(i => Console.Write($"{i} "));
  }

  private static void MaxEqualRowsAfterFlips(int[,] matrix) 
  {
    int m = matrix.GetLength(0);
    int n = matrix.GetLength(1);

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (matrix[j, i] == 0) matrix[j, i] = 1;
        else matrix[j, i] = 0;
      }
    }  
  }

  private static int[,] Transpose(int[,] matrix)
  {
    int rows = matrix.GetLength(0);
    int cols = matrix.GetLength(1);

    var trans = new int [cols, rows]; 
    for (int r = 0; r < rows; r++)
    {
      for (int c = 0; c < cols; c++)
      {
        trans[c, r] = matrix[r, c];
      }
    }  

    return trans;    
  }

  private static void PrintMatrix(int[,] matrix)
  {
    int rows = matrix.GetLength(0);
    int cols = matrix.GetLength(1);
    for (int r = 0; r < rows; r++)
    {
      for (int c = 0; c < cols; c++)
      {
        Console.Write($"{matrix[r, c]} ");
      }

      Console.WriteLine();
    }      
  }

  private static int[] GetColumn(int[,] matrix, int c)
  {
    int rows = matrix.GetLength(0);
    int cols = matrix.GetLength(1);

    var col = new int[rows];
    for(int r = 0; r < rows; r++)
    {
      col[r] = matrix[r, c];
    }

    return col;
  }

  private static int[] GetRow(int[,] matrix, int r)
  {
    int rows = matrix.GetLength(0);
    int cols = matrix.GetLength(1);

    var arr = new int[cols];
    for (int c = 0; c < cols; c++)
    {
      arr[c] = matrix[r, c];
    }

    return arr;
  }

   private static List<int> SpiralOrder(int[, ] matrix)
  {
    var list = new List<int>();
    int rows = matrix.GetLength(0);
    int cols = matrix.GetLength(1);

    int rowleft = 0;
    int rowright = rows - 1;
    int colup = 0;
    int coldown = cols - 1;
    int dir = 0;
    int toRemove = 0;
    while (coldown > rowleft)
    {
      if (dir % 4 == 0) // go right
      {
        var row = GetRow(matrix, rowleft).ToList();
        list.AddRange(row.Take(row.Count - toRemove));
        list.Add(0); // separator
        rowleft += 1;
        toRemove += 1;
      }
      else if (dir % 4 == 1) // go down
      {
        var col = GetColumn(matrix, coldown).ToList();
        list.AddRange(col.Skip(toRemove));
        list.Add(0);
        coldown -= 1;
      }
      else if (dir % 4 == 2) // go right
      {
        var row = GetRow(matrix, rowright).Reverse().ToList();
        list.AddRange(row.Take(row.Count - toRemove));
        list.Add(0);
        rowright -= 1;
      }
      else if (dir % 4 == 3) // go up
      {
        var col = GetColumn(matrix, colup).Reverse().ToList();
        list.AddRange(col.Take(col.Count - toRemove));
        list.Add(0);
        colup += 1;
      }
      dir += 1;
    }  
    return list;
  } 

  private static List<int> SpiralTraversal(int[, ] matrix)
  {
    var list = new List<int>();
    int rows = matrix.GetLength(0);
    int cols = matrix.GetLength(1);

    int r = 0;
    int c = 0;
    int dir = 0;
    while (r < rows && c < cols)
    { 

      // go right
      if (dir == 0)
      {
        for (int j = 0; j < cols; j++)
        {
          list.Add(int[r, j]);
        }
        rows -= 1;
        d += 1;
      }

      else if (d == 1)
      {
        for (int i = 0; i < rows; i++)
        {
          list.Add(int[i, c]);
        }
      }


    }
  }   
}
