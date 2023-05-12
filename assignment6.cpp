/*
A business house has several offices in different countries; they want to lease phone lines to 
connect them with each other and the phone company charges different rent to connect different 
pairs of cities. Business house want to connect all its offices with a minimum total cost. 
Represent using appropriate data structure. Apply Prim’s algorithm to find minimum total cost
*/

#include <iostream>
using namespace std;
#define MAX 20;
#define infinity 9999;
class Graph
{
    int G[20][20];
    int n;

public:
    Graph()
    {
        n = 0;
    }
    void readGraph();
    void printGraph();
    // void Dijkstra(int src);
    int prims( Graph &);
};
void Graph::readGraph()
{
    int i, j, Vi, Vj, no_of_edges, weight;
    cout << "Enter the no of vertices ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            G[i][j] = 0;
        }
    }
    cout << "Enter the of edges ";
    cin >> no_of_edges;
    cout << "Enter the list of edges ";
    for (i = 0; i < no_of_edges; i++)
    {
        cin >> Vi >> Vj >> weight;
        G[Vi][Vj] = G[Vj][Vi] = weight;
    }
}
void Graph ::printGraph()
{
    int i, j;
    cout << "Edges in the graph is ";
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (G[i][j] != 0)
            {
                cout << "\n(SRC,DEST,Weight) = " << i << " " << j << " " << G[i][j];
            }
        }
    }
}

int Graph ::prims(Graph &spanning)
{
    int cost[20][20];
    int u, v, min_distance;
    int distance[20];
    int from[20];
    int visited[20];
    int no_of_edges, i, min_cost, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (G[i][j] == 0)
            {
                cost[i][j] = infinity;
            }
            else
            {
                cost[i][j] = G[i][j];
            }
        }
    }
    spanning.n = n;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            spanning.G[i][j] = 0;
        }
    }
    distance[0] = 0;
    visited[0] = 1;
    for (i = 1; i < n; i++)
    {
        distance[i] = cost[0][i];
        from[i] = 0;
        visited[i] = 0;
    }
    min_cost = 0;
    no_of_edges = n - 1;
    while (no_of_edges > 0)
    {
        min_distance = infinity;
        for (i = 1; i < n; i++)
            if (visited[i] == 0 && distance[i] < min_distance)
            {
                v = i;
                min_distance = distance[i];
            }
        u = from[v];
        spanning.G[u][v] = distance[v];
        spanning.G[v][u] = distance[v];
        no_of_edges--;
        min_cost = min_cost + cost[u][v];
        visited[v] = 1;
        for (i = 1; i < n; i++)
            if (visited[i] == 0 && cost[v][i] < distance[i])
            {
                distance[i] = cost[v][i];
                from[i] = v;
            }
    }
    return (min_cost);
}

int main()
{
    Graph G, spanning;
    G.readGraph();
    cout << endl;
    cout << "Graph is \n";
    G.printGraph();
    int total_cost = G.prims(spanning);
    cout<<endl;
    cout << "spanning tree matrix : "<<endl;
    spanning.printGraph();
    cout<<endl;
    cout << "Total cost of spanning tree= " << total_cost<<endl;
    return 0;
}

/*Enter the no of vertices 8
Enter the of edges 10
Enter the list of edges
0 1 2
1 2 4
1 4 2
2 5 2
2 6 3
3 7 4
4 7 3
5 7 6
6 7 2

5 6 7

Graph is
Edges in the graph is
(SRC,DEST,Weight) = 0 1 2
(SRC,DEST,Weight) = 1 2 4
(SRC,DEST,Weight) = 1 4 2
(SRC,DEST,Weight) = 2 5 2
(SRC,DEST,Weight) = 2 6 3
(SRC,DEST,Weight) = 3 7 4
(SRC,DEST,Weight) = 4 7 3
(SRC,DEST,Weight) = 5 6 7
(SRC,DEST,Weight) = 5 7 6
(SRC,DEST,Weight) = 6 7 2
spanning tree matrix :
Edges in the graph is
(SRC,DEST,Weight) = 0 1 2
(SRC,DEST,Weight) = 1 4 2
(SRC,DEST,Weight) = 2 5 2
(SRC,DEST,Weight) = 2 6 3
(SRC,DEST,Weight) = 3 7 4
(SRC,DEST,Weight) = 4 7 3
(SRC,DEST,Weight) = 6 7 2
Total cost of spanning tree= 18 */

