using System;

public class Program
{
  public static void Main()
  {
    var arr = new int[] { 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 6, 6, 6, 6, 6, 6 };
    int val = 4;
    int lowindex = LowIndex(arr, val);
    int highindex = HighIndex(arr, val);

    Console.WriteLine($"Low index = {lowindex} High Index = {highindex}");
  }

  static int LowIndex(int[] arr, int value)
  {
    int h = arr.Length - 1;
    int l = 0;

    while (l <= h)
    {
      int mid = (h + l)/2;
      // keep moving high towards low if greater or equal
      if (arr[mid] >= value) h = mid - 1;
      else l = mid + 1;
    }

    if (arr[l] == value) return l;
    else return -1;
  }

  static int HighIndex(int[] arr, int value)
  {
    int h = arr.Length - 1;
    int l = 0;

    while (l <= h)
    {
      int mid = (h + l)/2;
      // keep moving low if lesser of equal
      if (arr[mid] <= value) l = mid + 1;
      else h = mid - 1;
    }

    if (arr[h] == value) return h;
    else return -1;
  }
}
