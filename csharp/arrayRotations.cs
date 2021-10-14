using System;
using System.Collections.Generic;
using System.Linq;

public class Program
{
  public static void Main()
  {
    var arr = new int[] {1, 2, 3, 4};
    int rotation = -2;
    arr = RotateArray(arr, rotation);
    Array.ForEach(arr, i => Console.Write($"{i} "));
  }

  private static int[] RotateArray(int[] arr, int rotation)
  {
    int len = arr.Length;
    rotation = rotation % len; // normalize 
    var rotated_arr = new int[len];
    int index;

    for (int i = 0; i < len; i++)
    {
      if (rotation > 0) index = (i + rotation) % len;
      else index = (i + rotation + len) % len; // +rotation is negative here (i - rot + len)
      rotated_arr[index] = arr[i]; 
    }

    return rotated_arr;
  }
}
