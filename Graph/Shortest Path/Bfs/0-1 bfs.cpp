#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void zeroOneBFS(int n, vector<vector<pair<int, int>>>& adj) {
    // Distance array, initialized with INF
    vector<int> dist(n, INF);
    dist[0] = 0;

    deque<int> dq;
    dq.push_front(0); // Start from node 0

    while (!dq.empty()) {
        int u = dq.front();
        dq.pop_front();

        for (auto [v, w] : adj[u]) {
            // If a shorter path to v is found
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                // Push v to front if w = 0, else to back
                if (w == 0)
                    dq.push_front(v);
                else
                    dq.push_back(v);
            }
        }
    }

    // Output distances
    for (int i = 0; i < n; i++) {
        cout << "Distance to node " << i << ": ";
        if (dist[i] == INF)
            cout << "INF\n";
        else
            cout << dist[i] << "\n";
    }
}

int main() {
    int n = 5; // Number of nodes
    vector<vector<pair<int, int>>> adj(n);

    // Example graph: (u, v, weight)
    adj[0].push_back({1, 0});
    adj[0].push_back({2, 1});
    adj[1].push_back({3, 1});
    adj[2].push_back({3, 0});
    adj[3].push_back({4, 1});

    zeroOneBFS(n, adj);

    return 0;
}
