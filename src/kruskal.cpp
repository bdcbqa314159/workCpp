#include <algorithm>
#include <iostream>

#include <vector>
typedef std::pair<int, int> edge;

class Graph
{
    std::vector<std::pair<int, edge>> G;
    std::vector<std::pair<int, edge>> T;
    std::vector<int> parent;
    int V;

public:
    Graph(int V);
    void addWeightedEdge(int u, int v, int w);
    int find_set(int i);
    void union_set(int u, int v);
    void kruskal();
    void print();
};

Graph::Graph(int V) : V(V)
{
    parent = std::vector<int>(V, 0);

    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
    }

    G.clear();
    T.clear();
}

void Graph::addWeightedEdge(int u, int v, int w)
{
    G.push_back(make_pair(w, edge(u, v)));
}

int Graph::find_set(int i)
{

    if (parent[i] == i)
    {
        return i;
    }

    else
    {
        return find_set(parent[i]);
    }
}

void Graph::union_set(int u, int v)
{
    parent[u] = parent[v];
}

void Graph::kruskal()
{

    int i{}, uRep{}, vRep{};
    std::sort(G.begin(), G.end());

    for (int i = 0; i < G.size(); i++)
    {
        uRep = find_set(G[i].second.first);
        vRep = find_set(G[i].second.second);

        if (uRep != vRep)
        {
            T.push_back(G[i]);
            union_set(uRep, vRep);
        }
    }
}

void Graph::print()
{

    std::cout << "Edge - Weight" << std::endl;

    for (int i = 0; i < T.size(); i++)
    {
        std::cout << T[i].second.first << " - " << T[i].second.second << " : " << T[i].first << std::endl;
    }
}

void KruskalTester()
{
    Graph g(6);
    // g.AddWeightedEdge(0, 1, 4);
    // g.AddWeightedEdge(0, 2, 4);
    // g.AddWeightedEdge(1, 2, 2);
    // g.AddWeightedEdge(1, 0, 4);
    // g.AddWeightedEdge(2, 0, 4);
    // g.AddWeightedEdge(2, 1, 2);
    // g.AddWeightedEdge(2, 3, 3);
    // g.AddWeightedEdge(2, 5, 2);
    // g.AddWeightedEdge(2, 4, 4);
    // g.AddWeightedEdge(3, 2, 3);
    // g.AddWeightedEdge(3, 4, 3);
    // g.AddWeightedEdge(4, 2, 4);
    // g.AddWeightedEdge(4, 3, 3);
    // g.AddWeightedEdge(5, 2, 2);
    // g.AddWeightedEdge(5, 4, 3);
    g.addWeightedEdge(0, 1, 9);
    g.addWeightedEdge(0, 2, 5);
    g.addWeightedEdge(0, 4, 11);
    g.addWeightedEdge(1, 2, 10);
    g.addWeightedEdge(1, 3, 12);
    g.addWeightedEdge(3, 4, 3);
    g.addWeightedEdge(3, 2, 7);
    g.addWeightedEdge(4, 2, 6);
    g.kruskal();
    g.print();
}

// void PrimsTester()
// {
//     // create the graph given in above fugure
//     int V = 5;
//     ankitTrilogy::Prim::Graph g(V);

//     //  making above shown graph
//     g.addEdge(0, 1, 4);
//     g.addEdge(0, 2, 8);
//     g.addEdge(1, 2, 2);
//     g.addEdge(1, 3, 6);
//     g.addEdge(2, 3, 3);
//     g.addEdge(2, 4, 9);
//     g.addEdge(3, 4, 5);
//     g.primMST();
//     g.print();
// }

int main()
{
    std::cout << "Testing tests.cpp" << std::endl;
    KruskalTester();
    // PrimsTester();
}