#include <vector>
#include <iostream>
#include <queue>

using namespace std;

void printBFS(vector<vector<int>> &graph, int vertex, vector<bool> &visited)
{

    int n = graph.size();
    queue<int> q;
    q.push(vertex);

    visited[vertex] = true;

    while (!q.empty())
    {

        int tempVertex = q.front();
        q.pop();

        cout << tempVertex << endl;

        for (int i = 0; i < n; i++)
        {

            if (graph[tempVertex][i] && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void BFS(vector<vector<int>> &graph)
{

    int n = graph.size();
    vector<bool> visited(n, false);
    int counter{};

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            printBFS(graph, i, visited);
            counter++;
        }
    }

    cout << "No. of connected components: " << counter << endl;
}

void printDFS(vector<vector<int>> &graph, int vertex, vector<bool> &visited)
{

    int n = graph.size();
    visited[vertex] = true;
    cout << vertex << endl;

    for (int i = 0; i < n; i++)
    {
        if (graph[vertex][i] && !visited[i])
        {
            printDFS(graph, i, visited);
        }
    }
}

void DFS(vector<vector<int>> &graph)
{

    int n = graph.size();
    vector<bool> visited(n, false);

    int counter{};

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            printDFS(graph, i, visited);
            counter++;
        }
    }

    cout << "No. of connected components: " << counter << endl;
}

void interactiveInputs()
{

    std::cout << "=== Dealing with inputs ===" << std::endl;

    int n, e;

    std::cin >> n >> e;
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));

    for (int i = 1; i <= e; i++)
    {
        int fv, sv;
        std::cin >> fv >> sv;
        matrix[fv][sv] = 1;
        matrix[sv][fv] = 1;
    }
    std::cout << "DFS" << std::endl;
    DFS(matrix);
    std::cout << "BFS" << std::endl;
    BFS(matrix);
}

void graphTester()
{
    std::cout << "Working with graphs :)." << std::endl;

    // Hardcoding graph
    int n = 7;
    int e = 4;
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
    matrix[0][1] = 1;
    matrix[1][0] = 1;
    matrix[0][4] = 1;
    matrix[4][0] = 1;
    matrix[1][4] = 1;
    matrix[4][1] = 1;
    matrix[2][5] = 1;
    matrix[5][2] = 1;

    std::cout << "DFS" << std::endl;
    DFS(matrix);
    std::cout << "BFS" << std::endl;
    BFS(matrix);

    std::vector<std::vector<int>> matrix1(6, std::vector<int>(6, 0));
    matrix1[0][1] = 1;
    matrix1[1][0] = 1;
    matrix1[1][2] = 1;
    matrix1[2][1] = 1;
    matrix1[1][3] = 1;
    matrix1[3][1] = 1;
    matrix1[2][4] = 1;
    matrix1[4][2] = 1;
    matrix1[4][5] = 1;
    matrix1[5][4] = 1;
    std::cout << "DFS" << std::endl;
    DFS(matrix1);
    std::cout << "BFS" << std::endl;
    BFS(matrix1);
}

int main()
{
    graphTester();
    return 0;
}