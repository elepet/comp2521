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

#include "standard.h"

#ifndef GRAPH_H
#define GRAPH_H

// Integer implementation.

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
bool GraphDFSRecurse(Graph g, int v, int w, bool visited[10]);
bool GraphDFS(Graph g, int v, int w);

// Perform DFS and return true if found cycle.
// Works for multiple connected nodes.
// Limited to 10 nodes 0~9.
bool GraphDFSHasCycleRecurse(Graph g, int v, int w, bool visited[10]);
bool GraphDFSHasCycle(Graph g, int v);

#endif
