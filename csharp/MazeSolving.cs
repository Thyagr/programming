using System;
using System.Collections.Generic;
using System.Linq;

public class Program
{
  public static int N = 4;

  private static bool IsSafeCell(int[][] Maze, int x, int y)
  {
    // check bounds and valid cell
    if (x >= 0 && y >= 0 && x < N && y < N && Maze[x][y] == 1)
      return true;
    
    return false;
  }

  private static bool SolveMaze(int[][] Maze, int x, int y, int[,] soln)
  {
    // if goal is reached
    if (x == N - 1 && y == N - 1)
    {
      soln[x, y] = 1;
      return true;
    }

    // check if x, y is a safe cell
    if (IsSafeCell(Maze, x, y) == true)
    {
      // check if current cell is already part of soln
      if (soln[x, y] == 1) 
        return false;

      // mark x,y part of soln
      soln[x, y] = 1;

      // move right
      if (SolveMaze(Maze, x + 1, y, soln))
        return true;
      
      // move down
      if (SolveMaze(Maze, x, y + 1, soln))
        return true;

      // move left
      if (SolveMaze(Maze, x - 1, y, soln))
        return true;

      // move up
      if (SolveMaze(Maze, x, y - 1, soln))
        return true;

      // If none of the above movements works then
      // BACKTRACK: unmark x, y as part of solution path
      soln[x, y] = 0;
      return false;
    }

    return false;
  }

  public static void Main()
  {
    var arr1 = new int[] { 1, 0, 0, 0 };
    var arr2 = new int[] { 1, 1, 0, 1 };
    var arr3 = new int[] { 0, 1, 1, 0 };
    var arr4 = new int[] { 1, 1, 1, 1 };

    var Maze = new int[][] {arr1, arr2, arr3, arr4};
    var rows = Maze.Length;
    var cols = Maze[0].Length;

    var soln = new int[N, N];
    var result = SolveMaze(Maze, 0, 0, soln);

    if (!result)
    {
      Console.WriteLine("No solution found");
      return;
    }

    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
        Console.Write(soln[i, j] + " ");
      Console.WriteLine();
    }
  }
}
