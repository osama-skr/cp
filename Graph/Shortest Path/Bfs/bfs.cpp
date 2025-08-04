#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;  // Adjacency list
vector<bool> visited;     // Marks visited nodes
vector<int> dist;         // Stores shortest distance from source

void bfs(int start) {
    queue<int> q;
    visited[start] = true;
    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;  // Distance from source
                q.push(v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; // n = number of nodes, m = number of edges
    cin >> n >> m;

    adj.assign(n + 1, {});
    visited.assign(n + 1, false);
    dist.assign(n + 1, -1);

    // Input edges
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Remove if directed graph
    }

    int start = 1; // Starting node
    bfs(start);

    // Output distances
    for (int i = 1; i <= n; ++i) {
        cout << "Distance from " << start << " to " << i << " = " << dist[i] << "\n";
    }

    return 0;
}
