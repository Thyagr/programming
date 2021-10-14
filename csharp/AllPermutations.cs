using System;
using System.Collections.Generic;
using System.Linq;

namespace AllPermutations
{
    public class Program
    {
        private static int count = 0;

        public static void Main()
        {
            var input = "@#$$!";

            // convert input into dictionary
            var dict = new Dictionary<char, int>();
            foreach (var i in input)
            {
                if (dict.ContainsKey(i)) dict[i] += 1;
                else dict[i] = 1;
            }

            var output = new char[input.Length];
            AllPermuations(dict, 0, output);
            Console.WriteLine($"Count = {count}");
        }

        private static void AllPermuations(Dictionary<char, int> dict, int index, char[] output)
        {
            count++;

            // case not permissible
            if (dict.Values.Any(i => i < 0))
            {
                return;
            }

            // if all are zero - exhausted dict
            if (dict.Values.All(i => i == 0))
            {
                Console.WriteLine(new string(output));
            }

            foreach (var key in dict.Keys)
            {
                if (dict[key] > 0)
                {
                    output[index] = key;
                    dict[key] -= 1;
                    AllPermuations(dict, index + 1, output);
                    dict[key] += 1; // need to re-add key value
                }
            }
        }
    }
}
