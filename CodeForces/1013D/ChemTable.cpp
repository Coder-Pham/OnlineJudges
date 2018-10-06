/**
 * Author:  Pham Trong Nhan
 * Date:    6/10/2018
**/

/**
 * R <=> C is a biparties graph
 * r1 -> c1 -> r2 -> c2 -> r1
 * So we just build up a biparties graph and go depth first search in it.
 * Every times, find a vertex not visited yet, increase component.
 * Result: component - 1 because the start point will be accidentally counted in 
 * 
 * Create BIPARTIES GRAPH: row (0->n-1) for row, row (n->m-1) for column.
 * Value in each intersection is: No. of row or col
**/

#include <iostream>
#include <vector>

int n, m, q;
std::vector<std::vector<int>> graph;
bool *visit;

void dps(int u)
{
    visit[u] = true;
    for (int v = 0; v < graph[u].size(); v++)
    {
        if (!visit[graph[u][v]])
        {
            dps(graph[u][v]);
        }
    }
}

int main(int argc, char const *argv[])
{
    std::cin >> n >> m >> q;
    graph.resize(n + m);
    visit = new bool(n + m);

    for (int i = 0; i < q; i++)
    {
        int row, col;
        std::cin >> row >> col;
        graph[row - 1].push_back(col - 1 + n);
        graph[col - 1 + n].push_back(row - 1);
    }

    int component = 0;
    for (int i = 0; i < n+m; i++)
    {
        if (!visit[i])
        {
            component++;
            dps(i);
        }
    }

    std::cout << component - 1;
    return 0;
}
