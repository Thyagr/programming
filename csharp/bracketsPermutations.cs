using System;
using System.Collections.Generic;

/*
Given an integer N representing the number of pairs of parentheses, the task is to generate 
all combinations of well-formed(balanced) parentheses.
*/
public class Program
{
	public static void Main()
	{
		int N = 4;
		var parens = new HashSet<string>();
		
    // find all permutations and check
    // var s = new string('(', N);
		// s += new string(')', N);
		// Permutations(s, 0, s.Length - 1, parens);
		
    //recursive implementation
		//here parens can be list instead of hashset (unique)
		// ca be extended to binary num (1, 0)
		var carr = new char[2 * N];
		AddParens(carr, 0, N, N, parens);
		foreach (var p in parens)
		{
			Console.WriteLine(p);
		}
	}

	// O(n*n!)
	private static void Permutations(string s, int l, int r, HashSet<string> parens)
	{
		if (l == r)
		{
			if (IsValidParen(s))
				parens.Add(s);
		}
		else
		{
			for (int i = l; i <= r; i++)
			{
				s = Swap(s, l, i);
				if (!parens.Contains(s)) // avoid repetitions
					Permutations(s, l + 1, r, parens);
			}
		}
	}

	// recursive implementation O(n) - time and space
	private static void AddParens(char[] carr, int count, int leftRem, int rightRem, HashSet<string> parens)
	{
		// invalid state
		if (leftRem < 0 || leftRem > rightRem) return;
		lef
		// no more parens
		if (leftRem == 0 && rightRem == 0)
		{
			parens.Add(new string (carr));
		}

		// add left if any left remaining
		if (leftRem > 0)
		{
			carr[count] = '(';
			AddParens(carr, count + 1, leftRem - 1, rightRem, parens);
		}

		// add right if any right remaining
		if (rightRem > 0)
		{
			carr[count] = ')';
			AddParens(carr, count + 1, leftRem, rightRem - 1, parens);
		}
	}

	private static string Swap(string s, int i, int j)
	{
		var carr = s.ToCharArray();
		var temp = carr[i];
		carr[i] = carr[j];
		carr[j] = temp;
		return new string (carr);
	}

	private static bool IsValidParen(string s)
	{
		var stack = new Stack<char>();
		var result = true;
		foreach (var t in s)
		{
			if (t == '(')
				stack.Push(t);
			else if (stack.Count > 0 && t == ')')
			{
				var g = stack.Pop();
				if (g != '(')
				{
					result = false;
					break;
				}
			}
		}

		return result && stack.Count == 0;
	}
}