using System;
using System.Collections.Generic;

namespace BinaryTreeCsharp
{
    public class Node
    {
        public int data;
        public Node left;
        public Node right;

        public Node(int value)
        {
            data = value;
            left = null;
            right = null;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Binary tree");

            Node root = null;

            root = AddNode(root, 10);
            root = AddNode(root, 20);
            root = AddNode(root, 5);
            root = AddNode(root, 8);
            root = AddNode(root, 4);
			root = AddNode(root, 6);

            Console.WriteLine("Inorder: ");
            InOrder(root);
            Console.WriteLine();

            Console.WriteLine("Level Order: ");
            LevelOrder(root);
            Console.WriteLine();

            Console.WriteLine("Tree height: " + TreeHeight(root));

            Console.WriteLine("Total nodes: " + CountNodes(root));

            var path = new List<int>();
            int val = 5;
            Console.WriteLine("Path to " + val + ": ");
            PrintPath(root, val, path);
            Console.WriteLine();
            //// path actually scans whole tree
            //Console.WriteLine();
            //path.ForEach(i => Console.Write(i + " "));

            int k = 1;
            Console.WriteLine($"Nodes at distance {k}: ");
            PrintAtDistanceK(root, k);
            Console.WriteLine();

            Console.WriteLine("Dictionary K levels");
            Dictionary<int, List<int>> dict = new Dictionary<int, List<int>>();
            LevelOrderDictionary(root, 0, dict);

            foreach (var d in dict)
            {
                Console.Write(d.Key + ": ");
                foreach (var e in d.Value)
                {
                    Console.Write(e + " " );
                }
                Console.WriteLine();
            }
			
			Console.WriteLine("Print path to all nodes");
			var paths = new int[100]; // use tree height when avaialble
			PrintPathToAllLeafNodes(root, paths, 0);


            Console.WriteLine("Inorder Hash: ");
			var dict2 = new Dictionary<string, int>();
			InOrderHash(root, dict);
			foreach (var kvp in dict2)
				Console.WriteLine(kvp.Key + ": " + kvp.Value);
        }

        public static Node AddNode(Node root, int value)
        {
            if (root == null)
            {
                root = new Node(value);
                return root;
            }

            if (value <= root.data) root.left = AddNode(root.left, value);
            else root.right = AddNode(root.right, value);

            return root;
        }

        public static void InOrder(Node root)
        {
            if (root == null) return;

            InOrder(root.left);
            Console.Write(root.data + " ");
            InOrder(root.right);
        }

        /*
		Store inoder subtrees in a hash
		'(', ')' represent null values of left, right child
		Use this to find if a tree is subtree (substring) of the other 
		We can use HashSet instead of Dict but cannot print multiple duplicates only once
		Use to check if 2 trees are equal without preorder ?? NO Inorder never unique E.g 1 -> 2( left and right same)
        More optimal: cracking the coding interview
		*/
		public static string InOrderHash(Node root, Dictionary<string, int> dict)
		{
			if (root == null) 
                return string.Empty; 
			
			string s = "("; // some char to mark null
			s += InOrderHash(root.left, dict);
			s += root.data.ToString();
			s += InOrderHash(root.right, dict);
			s += ")";
			
			if (dict.ContainsKey(s)) 
                dict[s] += 1;
			else 
                dict[s] = 1;
			
			return s;
		}

        /*
        This stores each level in a dictionary. E.g uses: sum of each level etc. 
        This is like preorder (depth first search)
        */
        public static void LevelOrderDictionary(Node root, int k, Dictionary<int, List<int>> levelDict)
        {
            if (root == null) return;

            if (levelDict.ContainsKey(k))
                levelDict[k].Add(root.data); // add to dict list
            else
                levelDict.Add(k, new List<int> { root.data }); // create dict entry

            LevelOrderDictionary(root.left, k + 1, levelDict);
            LevelOrderDictionary(root.right, k + 1, levelDict);
        }

        /*This is a BFS */
        public static void LevelOrder(Node root)
        {
            if (root == null) return;

            var Q = new List<Node> { root };
            while (Q.Count > 0)
            {
                root = Q[0]; // first element in queue
                Q.Remove(root); // take out of queue
                Console.Write(root.data + " ");

                if (root.left != null) Q.Add(root.left);
                if (root.right != null) Q.Add(root.right);
            }
        }

        public static int CountNodes(Node root)
        {
            if (root == null) return 0;
            
            int left = CountNodes(root.left);
            int right = CountNodes(root.right);

            return 1 + left + right; // +1 include root
        }

        public static int TreeHeight(Node root)
        {
            if (root == null) return -1;

            int left = CountNodes(root.left);
            int right = CountNodes(root.right);

            return 1 + (left > right ? left : right);
        }

        // Pre-order Root-L-R traversal
        public static void PrintPath(Node root, int val, int[] path, int index)
		{
			if (root == null)
				return;
            
			path[index] = root.data;
			if (root.data == val)
			{
				Console.Write("Path found.");
				for (int i = 0; i <= index; i++)
					Console.Write(path[i] + " ");
				return;
			}

			PrintPath(root.left, val, path, index + 1);
			PrintPath(root.right, val, path, index + 1);
		}

        public static void PrintAtDistanceK(Node root, int k)
        {
            if (root == null) return;

            if (k == 0)
            {
                Console.Write(root.data + " ");
                return;
            }

            PrintAtDistanceK(root.left, k - 1);
            PrintAtDistanceK(root.right, k - 1);
        }
		
		public static void PrintPathToAllLeafNodes(Node root, int[] paths, int index)
		{
			if (root == null) return;
			
			paths[index] = root.data;
			
			if (root.left == null && root.right == null)
			{
				Console.Write("Path to " + root.data + " = ");
                for (int i = 0; i <= index; i++)
					Console.Write(paths[i] + " ");
				Console.WriteLine();
                return;
			}
			
			PrintPathToAllLeafNodes(root.left, paths, index + 1);
            PrintPathToAllLeafNodes(root.right, paths, index + 1);
		}

        // mirror a binary tree 
        private static Node MirrorTree(Node root)
        {
            if (root == null) return root;

            // mirror the sub-trees
            Node leftTree = MirrorTree(root.left);
            Node rightTree = MirrorTree(root.right);
            
            // swap left and right
            root.left = rightTree;
            root.right = leftTree;

            return root;
        }

        /*
        To find distance between 2 nodes. Find paths to both nodes from root.
        Add them and substract 2*Path to common ancestor
        */
    }    
}
