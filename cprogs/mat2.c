
/*

In this coding exercise, you should implement the function IslandCount()
below, in C or C++.

IslandCount() takes three arguments that describe a "graph". A graph is a set
of "nodes" that are connected together by "edges". The ascii-art picture below
shows a graph with 8 nodes (numbered from 1..8) and 6 edges that are
represented by the horizontal and vertical lines.

    1---2---3   6    8
    |   |       |
    4---5       7

In this graph, nodes 1 and 2 are connected together by an edge, nodes 1 and 4
are connected, and so on. The arguments to IslandCount() that describe the
graph are
  * int N  - The number of nodes. Nodes are numbered consecutively from 1 to N.
             In the above example, N=8.
  * int M  - The number of edges. In the above example, N=6.
  * int *E - An integer array that contains pairs of elements that say which
             pairs of nodes are connected together.

For the above example the E array looks like this:

  E = {2, 3, 1, 2, 1, 4, 2, 5, 4, 5, 6, 7}

The first pair of elements is 2,3 which means that nodes 2 and 3 are connected
together. The second pair of elements is 1,2 which means that nodes 1 and 2 are
connected together. And so on. In total there are 2*M elements in the E array.

The goal of IslandCount() is to return the number of islands in the graph. An
island is a group of nodes that are connected only to themselves and not to any
of the other nodes in the graph. In the above example there are three islands.
The nodes 1,2,3,4,5 are connected only to themselves, so that's an island. The
nodes 6,7 are connected only to themselves, so that's an island. And node 8,
even though it's not connected to anything at all, is regarded as an island by
itself. In general, islands are distinct if there's no way to travel from one
to another by following the edges. Thus, in the above example IslandCount()
should return 3.

Some other things to note:

* Your goal is to write code that compiles and runs. Test cases are included at
  the bottom of this file, and you are finished when all of the test cases pass
  and "Success" is printed.
* Please add comments to your code to describe the approach you are taking.
* Your implementation should emphasize correctness, not speed. Don't worry
  at all about optimizing things.
* You can assume that all graphs are "well formed", so you don't need to check
  for weird error cases in the arguments.
* This HackerRank environment is set to C++, so you can use the C++ standard
  library, but if you are unfamiliar with C++ you can restrict yourself to basic
  C if you like.

Hints:

* The graph example above might suggest that nodes have positions in a two
  dimensional picture. But this is not the case.
* One common approach is to keep a record of the island that each node is in,
  then scan through pairs in the E array. Whenever you see that node X is
  connected to node Y, and we know the island of node X, then we also know the
  island of node Y.
* Another common approach is a depth (or breadth) first search, where you
  recursively jump from a node to its unvisited neighbors, to find all the
  nodes in an island.

*/

//---------------------------------------------------------------------------
// Here is where you should put your implementation.

#include <stdio.h>
#include <stdlib.h>

#define CHECK_EQ(a,b) if ((a) != (b)) { \
  printf("Check failed at line %d, %s != %s\n", __LINE__, #a, #b); \
  return 1; \
}


int Nodes;
int Edges;

void makeAdjMatrix(int adjMatrix[][Nodes+1], int pairsarr[][2])
{
    for (int i = 0; i < Nodes+1; i++)
    {
        int x = pairsarr[i][0];
        int y = pairsarr[0][i];
        adjMatrix[x][y] = 1;
        adjMatrix[y][x] = 1;
    }
}

int isOK(int adj[][Nodes+1], int visited[][Nodes+1], int x, int y)
{
    if ((x >= 0) && (x < (Nodes+1)) && (y > 0) && (y < Nodes+1)  && (adj[x][y] && !visited[x][y]))
        return 1;
    return 0;
}

void DFS(int adj[][Nodes+1], int visited[][Nodes+1], int x, int y)
{
    visited[x][y] = 1;
    
    for (int i = 0; i < Nodes+1; i++)
    {
        if (isOK(adj, visited, x, y))
        {
            DFS(adj, visited, x, y);
        }
    }
}

int IslandCount(int N, int M, int *E) {
 
 // create adjacency matrix
 Nodes = N;
 Edges = M;
 int adjMatrix[N+1][N+1];
 
 // initialize matrix to 0
 for (int i = 0; i < N+1; i++)
 {
     for (int j=0; j < N+1; j++)
     {
         adjMatrix[i][j] = 0;
     }
 }
 
 // go through the edges and find the pairs 
 int pairsarr[M/2][2];
 for (int i = 0; i < M; i += 2)
 {
     pairsarr[i/2][0] = E[i];
     pairsarr[i/2][1] = E[i+1];
 }
 
 // create an adjacency matrix with the given nodes and edges 
 makeAdjMatrix(adjMatrix, pairsarr);

for (int i = 0; i < N+1; i++)
 {
     for (int j= 0; j < N+1; j++)
     {
         printf("%d", adjMatrix[i][j]);
     }
    printf("\n");
 } 
 
 
 // find number of connected graphs
 // use DFS
 int visited[N+1][N+1];
 int islands = 0;
 for (int i = 0; i < N+1; i++)
 {
     for (int j = 0; j < N+1; j++)
     {
         if (adjMatrix[i][j] != visited[i][j])
         {
             DFS(adjMatrix, visited, i, j);
             islands += 1;
         }
     }
 }

 // return 
 return islands;
 
}

//----------------------------------------------------------------------------
// Here are the test cases for the IslandCount() function.


int main() {
  // The example graph:
  //   1---2---3   6    8
  //   |   |       |
  //   4---5       7
  int E1[] = {2, 3, 1, 2, 1, 4, 2, 5, 4, 5, 6, 7};
  CHECK_EQ(IslandCount(8, 6, E1), 3);

  // The example graph with node numbers reordered to try and trick IslandCount()
  // into prematurely counting islands.
  int E2[] = {1, 2, 3, 2, 6, 7, 4, 5, 2, 5, 4, 1};
  CHECK_EQ(IslandCount(8, 6, E2), 3);

  // No edges.
  CHECK_EQ(IslandCount(10, 0, NULL), 10);

  // Maximally connected.
  int E3[] = {1, 2, 2, 3, 3, 4, 4, 1, 1, 3, 2, 4};
  CHECK_EQ(IslandCount(4, 6, E3), 1);

  // No nodes or edges.
  CHECK_EQ(IslandCount(0, 0, NULL), 0);

  // Star configuration.
  int E4[] = {1, 2, 1, 3, 1, 4, 1, 5, 1, 6, 1, 7};
  CHECK_EQ(IslandCount(7, 6, E4), 1);

  // Two maximally connected islands.
  int E5[] = {1, 2, 2, 3, 3, 4, 4, 1, 1, 3, 2, 4, 5, 6, 6, 7, 7, 8, 8, 5, 5, 7, 6, 8};
  CHECK_EQ(IslandCount(8, 12, E5), 2);

  // Two maximally connected islands with a single link between them.
  int E6[] = {1, 2, 2, 3, 3, 4, 4, 1, 1, 3, 2, 4, 5, 6, 6, 7, 7, 8, 8, 5, 5, 7, 6, 8, 1, 8};
  CHECK_EQ(IslandCount(8, 13, E6), 1);

  printf("Success!\n");
  return 0;
}

