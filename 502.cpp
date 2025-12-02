#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj;  
vector<int> visited;

void dfs(int v) {
    visited[v] = 1;
    cout << v << " ";

    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
}

void bfs(int start) {
    vector<int> vis(adj.size(), 0);
    queue<int> q;

    vis[start] = 1;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";

        for (int u : adj[v]) {
            if (!vis[u]) {
                vis[u] = 1;
                q.push(u);
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    adj.assign(n, {});

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // remove this line for directed graph
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    cout << "\nDFS Traversal: ";
    visited.assign(n, 0);
    dfs(start);

    cout << "\nBFS Traversal: ";
    bfs(start);

    return 0;
}