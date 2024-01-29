#include <iostream>
#define size 4
using namespace std;
class graph
{
public:
    int i, j, wt, u, v, edges;
    int graf[size][size];
    graph();
    void read(int, int, int);
    void display();
    void degree();
    void prim();
};
graph::graph()
{
    for (i = 0; i < size; i++)
        for (j = 0; j < size; j++)
            graf[i][j] = 0;
}
void graph::read(int u, int v, int wt)
{
    graf[u][v] = wt;
    graf[v][u] = wt;
}
void graph::display()
{
    cout << "\nGraph is \n\n";
    for (int i = 0; i < size; i++)
    {
        cout << i << ":";
        for (int j = 0; j < size; j++)
        {
            cout << "\t" << graf[i][j];
        }
        cout << endl
             << endl;
    }
}
void graph::degree()
{
    int deg = 0;
    cout << "\nDegree of Vertex are: \n\n";
    for (int i = 0; i < size; i++)
    {
        deg = 0;
        for (int j = 0; j < size; j++)
        {
            if (graf[i][j] > 0)
                deg++;
        }
        cout << "Degree of Vertex " << i << "=" << deg << endl;
    }
    cout << endl;
}
void graph::prim()
{
    int x, y, wt = 0, count = 0, min = 0;
    int selected[size];
    for (int i = 0; i < size; i++)
    {
        selected[i] = 0;
    }
    selected[0] = 1;
    cout << "Selected nodes are:";
    while (count < size - 1)
    {
        min = 9999;
        for (int i = 0; i < size; i++)
        {
            if (selected[i] == 1)
            {
                for (int j = 0; j < size; j++)
                {
                    if (selected[j] == 0 && graf[i][j] != 0)
                    {
                        if (min > graf[i][j])
                        {
                            min = graf[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        cout << " " << y;
        selected[y] = 1;
        wt = wt + graf[x][y];
        count++;
    }
}
int main()
{
    graph g;
    g.read(6, 8, 3);
    g.read(3, 1, 9);
    g.read(1, 2, 5);
    g.read(1, 3, 6);
    g.display();
    g.degree();
    g.prim();
    return 0;
}
