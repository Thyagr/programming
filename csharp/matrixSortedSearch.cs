using System;
using System.Collections.Generic;
using System.Linq;

public class Program
{
  public static void Main()
  {
    int[] arr1 = new int[4] { 1, 0, 3, 4};
    int[] arr2 = new int[4] { 5, 6, 7, 8};
    int[] arr3 = new int[4] { 1, 3, 0, 1 };
    int[] arr4 = new int[4] { 5, 4, 3, 2 };  

    // Array.Sort(arr1);
    // Array.Sort(arr2);
    // Array.Sort(arr3);
    // Array.Sort(arr4);
    int[][] matrix = new int[][] {  arr1 ,  arr2 ,  arr3 ,  arr4  };

    // var pos = SearchSortedMatrix(matrix, 7);
    // Console.WriteLine(pos);
    MakeRowsColsZero(matrix);
    PrintMatrix(matrix);
  }

  private static (int, int) SearchSortedMatrix(int[][] matrix, int value)
  {
    int rows = matrix.Length;
    int cols = matrix[0].Length;

    var pos = (-1, -1);

    int r  = 0; 
    int c = cols - 1;

    /* To search for a value from top right
     going down (if greater) and left (if lesser)
     We can start from bottom left and go up and right (reversed)
    */
    while (r < rows && c >= 0) 
    {
      if (matrix[r][c] > value) 
        c -= 1;
      else if (matrix[r][c] < value) 
        r += 1;
      else {
        pos = (r, c);
        break;
      }
    }
    return pos;
  }

  private static void MakeRowsColsZero(int[][] matrix)
  {
    int rows = matrix.Length;
    int cols = matrix[0].Length;

    // so same value is not added twice
    var zeroRows = new HashSet<int>(); 
    var zeroCols = new HashSet<int>();

    for (int r = 0; r < rows; r++)
    {
      for (int c = 0; c < cols; c++)
      {
        if (matrix[r][c] == 0)
        {
          zeroRows.Add(r);
          zeroCols.Add(c);
        }
      }
    }

    // set row to zero
    foreach(var r in zeroRows)
    {
      for (int c = 0; c < cols; c++)
      {
        matrix[r][c] = 0;
      }
    }

    // set col to zero
    foreach(var c in zeroCols)
    {
      for (int r = 0; r < rows; r++)
      {
        matrix[r][c] = 0;
      }
    }
  }

  private static void PrintMatrix(int[][] matrix)
  {
    int rows = matrix.Length;
    int cols = matrix[0].Length;

    for (int r = 0; r < rows; r++)
    {
      for (int c = 0; c < cols; c++)
      {
        Console.Write($"{matrix[r][c]} ");
      }
      Console.WriteLine();
    }
  }
}
