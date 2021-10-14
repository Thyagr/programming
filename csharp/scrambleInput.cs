using System;
using System.Collections.Generic;
using System.Linq;

/*
Scrable the letters and chars (no special chars) by a given rotation
*/
public class Program
{
  public static void Main()
  {
    string input = "Zebra-679sklsflksj9uw94piowsjoi90uropw9uefokssj#!($Iipowe-p";
    int rot = 29;

    var output = ScrambleString(input, rot);
    Console.WriteLine(output);
  }

   private static string ScrambleString(string input, int rotations)
  {
    const string letters = "abcdefghijklmnopqrstuvwxyz";
    const string digits = "0123456789";
    char[] output = new char[input.Length]; // using array instead of string for efficiency
    int i = 0;
    foreach (var c in input)
    {
      if (letters.Contains(char.ToLower(c)))
      {
        int index = letters.IndexOf(c);
        index = (index + rotations) % letters.Length;
        if (char.IsUpper(c)) output[i] += char.ToUpper(letters[index]);
        else output[i] = letters[index];
      }
      else if (digits.Contains(c))
      {
        int index2 = digits.IndexOf(c);
        index2 = (index2 + rotations) % digits.Length;
        output[i] = digits[index2];
      }
      else 
      {
        output[i] = c;
      }

      i++;
    }

    return new string(output);
  }
}
