using System;
using System.Collections.Generic;

public class Program
{
	public static void Main()
	{
		var s = "this is a test string";
		var t = "tist";
		// WindowString(s, t);
		WindowOptimal(s, t);
	}

	// O(n) solution
	private static void WindowOptimal(string s, string t)
	{
		int len = s.Length;
        int left = 0;
		int right = 0;

		// dict for second string
        var dict2 = new Dictionary<char, int>();
		foreach (var i in t)
		{
			if (dict2.ContainsKey(i))
				dict2[i] += 1;
			else
				dict2[i] = 1;
		}

		var dict = new Dictionary<char, int>();
		while (left <= right && right < len)
		{
			if (dict.ContainsKey(s[right])) 
                dict[s[right]] += 1;
			else 
                dict[s[right]] = 1;

			// keep moving right and compare
			if (!CompareDicts(dict, dict2))
			{
				right++;
				continue;
			}

			// start removing left most element till it falls out
			while (CompareDicts(dict, dict2))
			{
                if (dict[s[left]] == 1)
                    dict.Remove(s[left]);
				else
					dict[s[left]] -= 1;

                left++;
			}

			// print from left index to right index
			// left - 1 = because we increment in loop before breaking
			// right - (left-1) + 1 (inclusive 1)
            Console.WriteLine($"Subs: {s.Substring(left - 1, right - left + 2)}");
            
            right++; // move the right counter so that not to double count at start
        }
	}

	private static bool CompareDicts(IReadOnlyDictionary<char, int> dict1, Dictionary<char, int> dict2)
	{
		foreach (var kvp in dict2)
		{
			if (!dict1.ContainsKey(kvp.Key) || dict1[kvp.Key] < kvp.Value)
				return false;
		}

		return true;
	}

	// sub-optimal, we generate all substrings O(n2)
	private static void WindowString(string s, string t)
	{
		int lens = s.Length;
		int lent = t.Length;
		int minLen = int.MaxValue;
		bool match = false;
		string minString = string.Empty;
		for (int i = 0; i < lens; i++)
		{
			if (!t.Contains(s[i].ToString())) continue;

			string subs = string.Empty;
			for (int j = 2; j <= lens - i; j++)
			{
				subs = s.Substring(i, j);
				if (CompareStrings(subs, t))
				{
					match = true;
					break;
				}
			}

			if (match && subs.Length < minLen)
			{
				Console.WriteLine(subs);
				minString = subs;
				minLen = minString.Length;
				match = false;
			}
		}

		Console.WriteLine("Substring: " + minString);
	}

	private static bool CompareStrings(string s1, string s2)
	{
		bool result = true;
		var hash = new HashSet<char>(s1);
		foreach (var c in s2)
		{
			if (!s1.Contains(c.ToString()))
			{
				result = false;
				break;
			}
		}

		return result;
	}
}