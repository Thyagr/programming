using System;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;
using System.Text;

public class Program
{
  public static void Main()
  {
    var sb = new StringBuilder();
    sb.Append("abc@def.com;");
    sb.AppendLine("apples");
    sb.Append("asd@sdf.co.uk");

    var text =  sb.ToString();
    emas(text);
  }

public static void emas(string text)
{
       const string MatchEmailPattern =
           @"(([\w-]+\.)+[\w-]+|([a-zA-Z]{1}|[\w-]{2,}))@"
           + @"((([0-1]?[0-9]{1,2}|25[0-5]|2[0-4][0-9])\.([0-1]?[0-9]{1,2}|25[0-5]|2[0-4][0-9])\."
             + @"([0-1]?[0-9]{1,2}|25[0-5]|2[0-4][0-9])\.([0-1]?[0-9]{1,2}|25[0-5]|2[0-4][0-9])){1}|"
           + @"([a-zA-Z]+[\w-]+\.)+[a-zA-Z]{2,4})";
            Regex rx = new Regex(MatchEmailPattern,  RegexOptions.Compiled | RegexOptions.IgnoreCase);
            // Find matches.
            MatchCollection matches = rx.Matches(text);
            // Report the number of matches found.
            int noOfMatches = matches.Count;
            // Report on each match.
            foreach (Match match in matches)
            {
                Console.WriteLine(match.Value.ToString());
            }
            Console.WriteLine();

                  Console.Write(text);
                  Console.WriteLine();
            string inputString = text;
              string pattern = MatchEmailPattern;
              string replacementString = "banana";
              // to replace strings of a pattern with another string
              string s = Regex.Replace(inputString, pattern, replacementString);
            Console.WriteLine();
            Console.Write(s);
        }
}
