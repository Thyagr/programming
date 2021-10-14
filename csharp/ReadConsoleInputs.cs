using System;

class Program
{
    static void Main(string[] args)
    {
        string s;

        string lstring = string.Empty;
        int len = 0;
        while ((s = Console.ReadLine()) != null)
        {
            var slen = s.Length;
            if (slen > len)
            {
                lstring = s;
                len = slen;
            }
        }

        Console.WriteLine($"Longest line: {lstring.Trim()}");
        Console.WriteLine($"Length: {len}");
    }
}