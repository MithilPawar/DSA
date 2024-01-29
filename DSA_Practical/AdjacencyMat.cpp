#include <iostream>
using namespace std;
class Graph
{
private:
    bool **adjMatrix;
    int numVertices;

public:
    Graph(int numVertices)
    {
        this->numVertices = numVertices;
        adjMatrix = new bool *[numVertices];
        for (int i = 0; i < numVertices; i++)
        {
            adjMatrix[i] = new bool[numVertices];
            for (int j = 0; j < numVertices; j++)
                adjMatrix[i][j] = false;
        }
    }
    void addEdge(int i, int j)
    {
        adjMatrix[i][j] = true;
        adjMatrix[j][i] = true; // For an undirected graph, only one assignment is needed
    }
    void removeEdge(int i, int j)
    {
        adjMatrix[i][j] = false;
        adjMatrix[j][i] = false;
    }
    void toString()
    {
        for (int i = 0; i < numVertices; i++)
        {
            cout << i << " ";
            for (int j = 0; j < numVertices; j++)
                cout << adjMatrix[i][j] << " ";
            cout << "\n";
        }
    }
    Graph()
    {
        for (int i = 0; i < numVertices; i++)
            delete[] adjMatrix[i];
        delete[] adjMatrix;
    }
};
int main()
{
    Graph g(4);
    g.addEdge(1, 1);
    g.addEdge(0, 2);
    g.addEdge(3, 2);
    g.addEdge(1, 0);
    g.addEdge(0, 3);
    g.toString();
    cout << "\nAfter removing edge between vertices 1 and 2:\n";
    g.removeEdge(1, 1);
    g.toString();
    return 0;
}
