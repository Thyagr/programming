using System;
using System.Collections.Generic;

public class Program
{
    public static void Main()
    {
        int[] arr = new int[] { -7, -3, -1, 4, 8, 12 };
        var sq_arr = Sorted_Square(arr);

        Array.ForEach(sq_arr, a => Console.Write($"{a} "));
    }

    private static int[] Sorted_Square(int[] arr)
    {
        int len = arr.Length;

        int left = 0;
        int right = len - 1;
        int sq_index = right;
        var sq_arr = new int[len];

        while (left <= right)
        {
            if (Math.Abs(arr[left]) > Math.Abs(arr[right]))
            {
                sq_arr[sq_index] = arr[left] * arr[left];
                left += 1;
            }
            else
            {
                sq_arr[sq_index] = arr[right] * arr[right];
                right -= 1;
            }

            sq_index -= 1;
        }

        return sq_arr;
    }
}
