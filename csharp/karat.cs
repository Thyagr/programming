/**
Suppose we have some input data describing a graph of relationships between parents and children over multiple generations. The data is formatted as a list of (parent, child) pairs, where each individual is assigned a unique positive integer identifier.

For example, in this diagram, 6 and 8 have common ancestors of 4 and 14.

             15
             |
         14  13
         |   |
1   2    4   12
 \ /   / | \ /
  3   5  8  9
   \ / \     \
    6   7     11
    
    
6 -> (3 -> 1), 5

6 -> (3 -> 1), (3 -> 2) 
6 -> (5 -> 4 ) 

parent_child_pairs_1 = [
    (1, 3), (2, 3), (3, 6), (5, 6), (5, 7), (4, 5),
    (4, 8), (4, 9), (9, 11), (14, 4), (13, 12),
   (12, 9), (15, 13)
]

Write a function that takes the graph, as well as two of the individuals in our dataset, as its inputs and returns true if and only if they share at least one ancestor.

Sample input and output:

has_common_ancestor(parent_child_pairs_1, 3, 8) => false
has_common_ancestor(parent_child_pairs_1, 5, 8) => true
has_common_ancestor(parent_child_pairs_1, 6, 8) => true
has_common_ancestor(parent_child_pairs_1, 6, 9) => true
has_common_ancestor(parent_child_pairs_1, 1, 3) => false
has_common_ancestor(parent_child_pairs_1, 3, 1) => false
has_common_ancestor(parent_child_pairs_1, 7, 11) => true
has_common_ancestor(parent_child_pairs_1, 6, 5) => true
has_common_ancestor(parent_child_pairs_1, 5, 6) => true

Additional example: In this diagram, 4 and 12 have a common ancestor of 11.

        11
       /  \
      10   12
     /  \
1   2    5
 \ /    / \
  3    6   7
   \        \
    4        8

parent_child_pairs_2 = [
    (1, 3), (11, 10), (11, 12), (2, 3), (10, 2),
    (10, 5), (3, 4), (5, 6), (5, 7), (7, 8),
]

has_common_ancestor(parent_child_pairs_2, 4, 12) => true
has_common_ancestor(parent_child_pairs_2, 1, 6) => false
has_common_ancestor(parent_child_pairs_2, 1, 12) => false

n: number of pairs in the input


**/

using System;
using System.Collections.Generic;
using System.Linq;

public class Program
{
    public static void Main()
    {
        var parentChildPairs1 = new List<int[]>() {
            new int[]{1, 3},
            new int[]{2, 3},
            new int[]{3, 6},
            new int[]{5, 6},
            new int[]{5, 7},
            new int[]{4, 5},
            new int[]{4, 8},
            new int[]{4, 9},
            new int[]{9, 11},
            new int[]{14, 4},
            new int[]{13, 12},
            new int[]{12, 9},
            new int[]{15, 13}
        };

        var result = findNodesWithZeroAndOneParents(parentChildPairs1);
        foreach (var r in result)
        {
            Array.ForEach(r, i => Console.Write(i + " "));
            Console.WriteLine();
        }

        var parent_child_pairs_1 = new List<int[]>() {
            new int[] {1, 3}, new int[] {2, 3}, new int[] {3, 6}, new int[] {5, 6},  new int[] {5, 7}, new int[] {4, 5},
            new int[] {4, 8}, new int[] {4, 9}, new int[] {9, 11}, new int[] {14, 4}, new int[] {13, 12},
            new int[] {12, 9}, new int[] {15, 13}};

        Console.WriteLine(has_common_ancestor(parent_child_pairs_1, 8, 12));
        Console.WriteLine(has_common_ancestor(parent_child_pairs_1, 5, 8));
        Console.WriteLine(has_common_ancestor(parent_child_pairs_1, 6, 8));
        Console.WriteLine(has_common_ancestor(parent_child_pairs_1, 6, 9));
        Console.WriteLine(has_common_ancestor(parent_child_pairs_1, 11, 6));
        Console.WriteLine(has_common_ancestor(parent_child_pairs_1, 3, 1));
        Console.WriteLine(has_common_ancestor(parent_child_pairs_1, 7, 11));
        Console.WriteLine(has_common_ancestor(parent_child_pairs_1, 6, 5));
        Console.WriteLine(has_common_ancestor(parent_child_pairs_1, 5, 6));
    }

    private static List<int[]> findNodesWithZeroAndOneParents(List<int[]> pc)
    {
        var dict = new Dictionary<int, List<int>>();
        var hash = new HashSet<int>();
        foreach (var l in pc)
        {
            hash.Add(l[0]);
            hash.Add(l[1]);

            if (dict.ContainsKey(l[1])) 
                dict[l[1]].Add(l[0]);
            else 
                dict[l[1]] = new List<int> { l[0] };
        }

        var oneParent = new List<int>();
        foreach (var kvp in dict)
        {
            if (kvp.Value.Count == 1)
                oneParent.Add(kvp.Key);
        }

        var zeroParents = new List<int>();
        foreach (var h in hash)
        {
            if (!dict.ContainsKey(h))
                zeroParents.Add(h);
        }

        return new List<int[]>
        {
            zeroParents.ToArray(),
            oneParent.ToArray(),
        };
    }

    private static bool has_common_ancestor(List<int[]> pc, int node1, int node2)
    {
        var dict = new Dictionary<int, List<int>>();
        foreach (var l in pc)
        {
            if (dict.ContainsKey(l[1]))
                dict[l[1]].Add(l[0]);
            else
                dict[l[1]] = new List<int> { l[0] };
        }

        var hash1 = new HashSet<int> { node1 };
        var hash2 = new HashSet<int> { node2 };

        get_ancestors(node1, dict, hash1);
        get_ancestors(node2, dict, hash2);

        return hash1.Intersect(hash2).Any();
    }

    private static void get_ancestors(int node, Dictionary<int, List<int>> dict, HashSet<int> hash)
    {
        var q = new Queue<int>();
        q.Enqueue(node);

        while (q.Count > 0)
        {
            int front = q.Dequeue();
            if (!dict.ContainsKey(front)) continue;
            foreach (var d in dict[front])
            {
                q.Enqueue(d);
                hash.Add(d);
            }
        }
    }
}
