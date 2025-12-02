#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> adj(n, vector<int>(n));
    cout << "Enter adjacency matrix (0 for no edge):\n";

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adj[i][j];

    int src, dest;
    cout << "Enter source node: ";
    cin >> src;
    cout << "Enter destination node: ";
    cin >> dest;

    const int INF = 1e9;
    vector<int> dist(n, INF);
    vector<int> visited(n, 0);

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        // find min-distance unvisited node
        int u = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u]))
                u = i;
        }

        visited[u] = 1;

        // relax edges
        for (int v = 0; v < n; v++) {
            if (adj[u][v] > 0 && !visited[v] && dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }

    cout << "\nShortest distance from " << src
         << " to " << dest << " = " << dist[dest] << "\n";

    return 0;
}