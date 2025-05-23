// Lev K. 2025

// A graph is a data structure where each node is connected to arbitrarily many nodes, as opposed to linked lists and trees.
// Examples of graphs: cities connected by roads on a map, pages connected by links on the web.

// In a graph, the set of vertices is called V and the set of edges is called E.
// Vertices are labelled with an identifier (will use integers, starting from 0).
// Edges may be optionally directed, weighted, looped, and/or be labelled.
// For a simple graph (undirected, no loops, no multiple edges), the maximum number of edges is E = V * (V - 1) / 2.
// Two vertices are said to be adjacent if an edge connects them, and that edge is said to be incident on the two vertices.
// The degree of a vertex is the number of edges incident on it.
// If E is closer of V^2, the graph is said to be dense. If E is closer to V, the graph is said to be sparse. This determines our choice of representation and algorithms.
// A path is a sequence of vertices where each has an edge to the next. A path is simple if it has no repeating vertices. A cycle is a path where only the first and last vertices are the same.
// A complete graph is one where every vertex is connected to every other vertex by an edge (max. no. of edges).
// A connected graph is one where there is a path from every vertex to every other vertex.
// A tree is a connected graph with no cycles. A tree has exactly one path between each pair of vertices.
// A subgraph is a graph that contains a subset of the vertices and edges of another graph.
// A connected component is a maximally connected subgraph. A connected graph has one connected component while a disconnected graph has multiple.
// A spanning tree is a subgraph that contains all the vertices of another graph and is a single tree. Spanning trees only exist for connected graphs.
// A spanning forest is a subgraph that contains all the vertices of another graph and contains one tree for each connected component.
// A clique is a complete subgraph. A clique is non-trivial if it contains >= 3 vertices.

// Representations:
// - Adjacency matrix. Edges defined by presence value in V * V matrix.
// 	Pros: O(1) edge insertion / deletion and adjacency check.
// 	Cons: O(V^2) memory usage.
// - Adjacency list. Edges defined by entries (neighbours) in array of V lists.
// 	Pros: O(V + E) memory usage.
// 	Cons: O(V) edge insertion / deletion.
// - Array of edges. Explicit representation of edges as vertex pairs.
// 	Pros: space efficient for sparse graphs.
// 	Cons: O(E) insertion / deletion.
// Note: none of these require edge labels.

// Breadth First Search (BFS). Implemented iteratively with a queue. 
// Depth First Search (DFS). Implemented recursively or iteratively with a stack.
// In a tree these work exactly as their names imply.
// In a graph, BFS works on distance (in vertices) from the start, while DFS works on priority.
// BFS can be used to find the shortest path (in vertices), while DFS can be used to check whether a path exists.
// Both of these can be used to form spanning trees.

// Directed graphs (digraphs) are those where the edges have direction.
// Examples: follows on social media, one-way streets.
// The in-degree is the number of incoming edges to a vertex, and vice versa for out-degree.
// A directed path is a sequence of vertices where each vetex has an outgoing edge to the next.
// If there is a directed path from v to w, then it is said that w is reachable from v.
// A directed cycle is a directed path where the first and last vertices are the same.
// A digraph is strongly connected if there is a directed path from every vertex to every other.
// A strongly-connected component is a maximally strongly-connected subgraph.
// A digraph that is not strongly connected has two or more strongly-connected components.
// Digraph representations are the same as undirected graphs.
// Representations are changed as follows for each representation:
// - Adjacency matrix. Store weight in each cell (not just t/f). Also need value to represent no edge.
// - Adjacency list. Store weight as node value and use node no. in list to represent index.
// - Array of edges. Add weight to each edge.

// A spanning tree of an undirected graph is a subgraph that contains all the vertices, is connected, and contains no cycles.
// A minimum spanning tree (MST) of an undirected weighted graph is a spanning tree that has minimum total edge weight among all spanning trees for that graph.
// Useful anywhere where we want to connect nodes as cheaply as possible.
// Two algorithms to contruct MSTs from graphs:
// - Kruskal's algorithm. Start with empty graph with same vertices as original graph. Consider edges by ascending weight and add each if it does not form a cycle in the MST. Repeat until V - 1 edges have been added. O(E * V) using adjacency list and O(E * log(V)) using union-find. Better for sparse graphs.
// - Prim's algorithm. Start with empty graph with same vertices as original graph. Start from any vertex and add it to the MST. Choose cheapest edge such that source has been added to MST while target hasn't and add it and the target vertex to the MST. Repeat until V - 1 edges have been added. O(V * E) using set of edges and O(E + V * log(V)) using Fibonacci heap. Better for dense graphs.

#include "standard.h"

#ifndef GRAPH_H
#define GRAPH_H

// ============================================ UNWEIGHTED UNDIRECTED.

// Node indices are integers, denoted by v and w.

struct graph;
typedef struct graph *Graph;

// Dynamically allocate graph with n vertices.
Graph GraphNew(int nV);

// Insert edge. 
void GraphInsertEdge(Graph g, int v, int w);

// Remove edge.
void GraphRemoveEdge(Graph g, int v, int w);

// Free all memory allocated to graph.
void GraphFree(Graph g);

// Print graph.
void GraphPrint(Graph g);

// Return number of vertices in graph.
int GraphNumVertices(Graph g);

// Return number of edges in graph.
int GraphNumEdges(Graph g);

// Check adjacency.
bool GraphIsAdjacent(Graph g, int v, int w);

// Perform BFS from v and print predecessors.
// Limited to 10 nodes 0~9.
//void GraphBFS(Graph g, int v);

// Perform DFS and return true if found path between vertices v and w.
// Limited to 10 nodes 0~9.
// O(V + E).
bool GraphDFSRecurse(Graph g, int v, int w, bool visited[10]);
bool GraphDFS(Graph g, int v, int w);

// Perform DFS and return true if found cycle.
// Works for multiple connected nodes.
// Limited to 10 nodes 0~9.
// O(V + E).
bool GraphDFSHasCycleRecurse(Graph g, int v, int w, bool visited[10]);
bool GraphDFSHasCycle(Graph g, int v);

// ============================================ WEIGHTED DIRECTED.

// These do the same as their above equivalents but for weighted and directed graphs.
// Here, vI and wI are node indices while vW and wW are their corresponding weights.
// Limited to 10 nodes 0~9.
// Instead of the value of a node being the index of the neighbour, it is the weight of the edge to that neighbour and its order in the list is the index of the neighbour.
// Absent edges have value == -1, so this implementation only works for non-negative weights.
// If the weight for an edge is only present in the neighbours list of one node, this means it is one-way.
// Functions above that are not here can be used for both unw/und and w/d graphs.
// Two-way edges count as two edges.

Graph WDGraphNew(void);
void WDGraphInsertEdge(Graph g, int vI, int vW, int wI, int wW);
void WDGraphRemoveEdge(Graph g, int vI, int wI);
bool WDGraphIsAdjacent(Graph g, int vI, int wI);
bool WDGraphDFSRecurse(Graph g, int vI, int wI, bool visited[10]);
bool WDGraphDFS(Graph g, int vI, int wI);
bool WDGraphDFSHasCycleRecurse(Graph g, int vI, bool visited[10], bool onStack[10]);
bool WDGraphDFSHasCycle(Graph g, int vI);

// If shortestPath == true, print the shortest path between vI and wI.
// Else print the shortest path between source node and every other node.
// Shortest path here means minimum total weight.
void WDGraphDijkstra(Graph g, int vI, bool shortestPath, int wI);

#endif

