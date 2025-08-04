#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int MAXN = 100005;

int n, m;  // nodes and edges
vector<pair<int, int>> adj[MAXN]; // {to, weight}
int dist[MAXN];
bool inQueue[MAXN];

void spfa(int src) {
    for (int i = 0; i <= n; i++) dist[i] = INF;
    dist[src] = 0;

    queue<int> q;
    q.push(src);
    inQueue[src] = true;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        inQueue[u] = false;

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;

                // Only push if not already in queue
                if (!inQueue[v]) {
                    q.push(v);
                    inQueue[v] = true;
                }
            }
        }
    }
}

int32_t main() {
    cin >> n >> m;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        // for undirected graph: adj[v].push_back({u, w});
    }

    int src;
    cin >> src;
    spfa(src);

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) cout << "INF ";
        else cout << dist[i] << " ";
    }

    return 0;
}
