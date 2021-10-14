using System;
using System.Collections.Generic;

namespace DFSUtil
{
	public class Graph
	{
		readonly List<int>[] AdjacencyList = null;
		readonly int VertexCount = 0;
		public Graph(int vertexCount)
		{
			VertexCount = vertexCount;
			AdjacencyList = new List<int>[VertexCount];
			for (int i = 0; i < VertexCount; i++)
				AdjacencyList[i] = new List<int>();
		}

		public void AddEdge(int v, int w)
		{
			AdjacencyList[v].Add(w);
		}

		private void DfsUtil(int vertex, bool[] visited)
		{
			visited[vertex] = true; // mark visited
			Console.WriteLine($"Visited: {vertex}"); // visit it 
			foreach (var v in AdjacencyList[vertex])
			{
				if (!visited[v])
				{
					DfsUtil(v, visited);
				}
			}
		}

		public void Dfs()
		{
			var visited = new bool[VertexCount];
			// the Util helps in case of a disconnected graph
			for (int vertex = 0; vertex < VertexCount; vertex++)
			{
				if (visited[vertex] == false)
					DfsUtil(vertex, visited);
			}
		}

		public void Bfs(int vertex)
		{
			var visited = new bool[VertexCount];
			var Q = new List<int>();

			visited[vertex] = true;
			Q.Add(vertex);
			while (Q.Count > 0)
			{
				// Dequeue a vertex from queue and print it
				var v = Q[0]; // front of Q
				Console.WriteLine($"Visited: {v}"); // visit it
				Q.Remove(v);
				foreach (var w in AdjacencyList[v])
				{
					if (!visited[w])
					{
						visited[w] = true;
						Q.Add(w);
					}
				}
			}
		}

		// O(V + E) = same as DFS
		private bool IsCyclicUtil(int vertex, bool[] visited, bool[] recStack)
		{
			// mark node as visited and part of rec stack
			visited[vertex] = true;
			recStack[vertex] = true;
			foreach (var v in AdjacencyList[vertex])
			{
				// check if not visited and call function
				if (!visited[v] && IsCyclicUtil(v, visited, recStack))
					return true;
				else if (recStack[v] == true) // part of the rec stack
					return true;
			}

			recStack[vertex] = false; // remove vertex from rec stack
			return false;
		}

		public bool IsCyclic()
		{
			// recursion stack = array to keep track of nodes visited in cycle 
			var recStack = new bool[VertexCount];
			var visited = new bool[VertexCount];
			for (int vertex = 0; vertex < VertexCount; vertex++)
			{
				if (IsCyclicUtil(vertex, visited, recStack))
					return true;
			}

			return false;
		}

		private void TopologicalUtil(int vertex, bool[] visited, Stack<int> stack)
		{
			visited[vertex] = true;
			foreach (var v in AdjacencyList[vertex])
			{
				if (!visited[v])
					TopologicalUtil(v, visited, stack);
			}

			// push current vertex into the stack
			stack.Push(vertex);
		}

		/* 
        Topological sort: Linear ordering of vertices such that every edge (v, w) v comes befor w
        Build systems (library dependancy), Task scheduling and Pre-requisite problems
		Similar to DFS (uses stack to push item)
        */
		public void TopologicalSort()
		{
			var visited = new bool[VertexCount];
			var stack = new Stack<int>();
            
			for (var vertex = 0; vertex < VertexCount; vertex++)
			{
				if (!visited[vertex])
					TopologicalUtil(vertex, visited, stack);
			}

			while (stack.Count > 0)
			{
				Console.WriteLine(stack.Pop());
			}
		}
	}

	public class Program
	{
		public static void Main()
		{
			var g = new Graph(4);
			g.AddEdge(0, 1);
			g.AddEdge(0, 2);
			g.AddEdge(1, 2);
			g.AddEdge(2, 0);
			g.AddEdge(2, 3);
			g.AddEdge(3, 3);
			g.AddEdge(3, 2);
			g.AddEdge(3, 1);
			Console.WriteLine("Depth First Search");
			g.Dfs();
			Console.WriteLine("\nBreadth First Search");
			g.Bfs(2);
			Console.WriteLine("\nTopological Sort");
			Graph g2 = new Graph(6);
			g2.AddEdge(5, 2);
			g2.AddEdge(5, 0);
			g2.AddEdge(4, 0);
			g2.AddEdge(4, 1);
			g2.AddEdge(2, 3);
			g2.AddEdge(3, 1);
			g2.TopologicalSort();
			Console.WriteLine("\nCycle detection");
			Graph g3 = new Graph(4);
			g3.AddEdge(0, 1);
			g3.AddEdge(0, 2);
			g3.AddEdge(1, 2);
			g3.AddEdge(2, 0);
			g3.AddEdge(2, 3);
			g3.AddEdge(3, 3);
			if (g3.IsCyclic())
				Console.WriteLine("Graph contains cycle.");
			else
				Console.WriteLine("Graph doesn't contain cycle.");
		}
	}
}