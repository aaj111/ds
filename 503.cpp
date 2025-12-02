#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<pair<int,int>>> adj;  
// adj[u] contains pairs (v, weight)

void prim(int n, int start) {
    vector<int> visited(n, 0);
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    // (weight, node)
    pq.push({0, start});

    int mst_cost = 0;

    cout << "\nEdges in MST:\n";

    while (!pq.empty()) {
        auto [wt, u] = pq.top();
        pq.pop();

        if (visited[u]) continue;
        visited[u] = 1;
        mst_cost += wt;

        if (wt != 0)
            cout << "Selected edge with weight " << wt << " ending at vertex " << u << "\n";

        for (auto &p : adj[u]) {
            int v = p.first;
            int w = p.second;
            if (!visited[v]) {
                pq.push({w, v});
            }
        }
    }

    cout << "\nTotal cost of MST = " << mst_cost << "\n";
}

int main() {
    int n, m;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    adj.assign(n, {});

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});  // undirected
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    prim(n, start);

    return 0;
}