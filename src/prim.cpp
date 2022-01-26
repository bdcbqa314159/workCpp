#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define INF 0x3f3f3f3f

// iPair ==>  Integer Pair
typedef pair<int, int> iPair;

// This class represents a directed graph using
// adjacency list representation
class Graph
{
    int V; // No. of vertices

    // In a weighted graph, we need to store vertex
    // and weight pair for every edge
    vector<vector<pair<int, int>>> adj;
    vector<pair<int, iPair>> T;

public:
    Graph(int V); // Constructor

    // function to add an edge to graph
    void addEdge(int u, int v, int w);

    // Print MST using Prim's algorithm
    void primMST();

    void print();
};

// Allocates memory for adjacency list
Graph::Graph(int V) : V(V)
{
    adj = vector<vector<pair<int, int>>>(V);
    T.clear();
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

// Prints shortest paths from src to all other vertices
void Graph::primMST()
{
    // Create a priority queue to store vertices that
    // are being preinMST. This is weird syntax in C++.
    // Refer below link for details of this syntax
    // http://geeksquiz.com/implement-min-heap-using-stl/
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

    int src = 0; // Taking vertex 0 as source

    // Create a vector for keys and initialize all
    // keys as infinite (INF)
    vector<int> key(V, INF);

    // To store parent array which in turn store MST
    vector<int> parent(V, -1);

    // To keep track of vertices included in MST
    vector<bool> inMST(V, false);

    // Insert source itself in priority queue and initialize
    // its key as 0.
    pq.push(make_pair(0, src));
    key[src] = 0;

    /* Looping till priority queue becomes empty */
    while (!pq.empty())
    {
        // The first vertex in pair is the minimum key
        // vertex, extract it from priority queue.
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted key (key must be first item
        // in pair)
        int u = pq.top().second;
        pq.pop();

        // Different key values for same vertex may exist in the priority queue.
        // The one with the least key value is always processed first.
        // Therefore, ignore the rest.
        if (inMST[u] == true)
        {
            continue;
        }

        inMST[u] = true; // Include vertex in MST

        // 'i' is used to get all adjacent vertices of a vertex
        for (auto &x : adj[u])
        {
            int v = x.first;
            int weight = x.second;
            if (inMST[v] == false && key[v] > weight)
            {
                // Updating key of v
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }

    // // Print edges of MST using parent array
    // for (int i = 1; i < V; ++i)
    //     printf("%d - %d\n", parent[i], i);

    for (int i = 1; i < V; i++)
    {
        T.push_back(make_pair(parent[i], make_pair(i, key[i])));
    }
}

void Graph::print()
{

    std::cout << "Edge - Weight" << std::endl;

    for (int i = 0; i < T.size(); i++)
    {
        std::cout << T[i].first << " - " << T[i].second.first << " : " << T[i].second.second << std::endl;
    }
    return;
}
// Driver program to test methods of graph class

void PrimsTester()
{
    // create the graph given in above fugure
    int V = 5;
    Graph g(V);

    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 8);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 3);
    g.addEdge(2, 4, 9);
    g.addEdge(3, 4, 5);
    g.primMST();
    g.print();
}

int main()
{
    std::cout << "Testing tests.cpp" << std::endl;
    // KruskalTester();
    PrimsTester();
}