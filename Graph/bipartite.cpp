#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define Meligy ios::sync_with_stdio(false); cin.tie(NULL);

const int N = 2e5 + 5;
vector<int> adj[N];
int color[N]; // 0: unvisited, 1 or 2: group

bool bfs(int start) {
    queue<int> q;
    q.push(start);
    color[start] = 1; // First group

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto neighbor : adj[node]) {
            if (color[neighbor] == 0) {
                color[neighbor] = 3 - color[node]; // Toggle between 1 and 2
                q.push(neighbor);
            }
            else if (color[neighbor] == color[node]) {
                // Not bipartite
                return false;
            }
        }
    }
    return true;
}

int main() {
    Meligy
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool is_bipartite = true;
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            if (!bfs(i)) {
                is_bipartite = false;
                break;
            }
        }
    }

    if (!is_bipartite) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        vector<int> group1, group2;
        for (int i = 1; i <= n; i++) {
            if (color[i] == 1) group1.push_back(i);
            else if (color[i] == 2) group2.push_back(i);
        }

        cout << "Group 1: ";
        for (int x : group1) cout << x << " ";
        cout << "\n";

        cout << "Group 2: ";
        for (int x : group2) cout << x << " ";
        cout << "\n";
    }

    return 0;
}
