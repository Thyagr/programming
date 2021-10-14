using System;

public class Program
{
  public static void Main()
  {
    var rlen = 16;
    Console.WriteLine(RandString(rlen));
    Console.WriteLine(RandString(rlen));
    Console.WriteLine(RandString(rlen));
  }

  private static string RandString(int len)
  {
    if (len <= 0) return null;
    
    const string Alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    var carr = new char[len];
    var rand = new Random();

    for (int i = 0; i < len; i++)
    {
      carr[i] = Alphabet[rand.Next(0, Alphabet.Length)];
    }

    return new string(carr);
  }
}