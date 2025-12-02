#include <iostream>
#include <queue>
using namespace std;

void dfs(int v, int n, int adj[10][10], int visited[]) {
    visited[v] = 1;
    cout << v << " ";

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            dfs(i, n, adj, visited);
        }
    }
}

void bfs(int start, int n, int adj[10][10]) {
    int visited[10] = {0};
    queue<int> q;

    visited[start] = 1;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";

        for (int i = 0; i < n; i++) {
            if (adj[v][i] == 1 && !visited[i]) {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    int adj[10][10];
    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adj[i][j];

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    cout << "\nDFS Traversal: ";
    int visited[10] = {0};
    dfs(start, n, adj, visited);

    cout << "\nBFS Traversal: ";
    bfs(start, n, adj);

    return 0;
}