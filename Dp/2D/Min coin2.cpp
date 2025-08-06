#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e6 + 7;
const ll INF = 1e18;
int dp[N], par[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    fill(dp, dp + t + 1, INT_MAX);
    dp[0] = 0;
    par[0] = -1;

    for (int i = 0; i < n; i++) {
        for (int j = t; j >= a[i]; j--) {
            if (dp[j - a[i]] != INT_MAX && dp[j - a[i]] + 1 < dp[j]) {
                dp[j] = dp[j - a[i]] + 1;
                par[j] = j - a[i];
            }
        }
    }

    if (dp[t] == INT_MAX) {
        cout << -1 << "\n";
        return 0;
    }

    cout << dp[t] << "\n"; // min number of coins

    // Reconstruct path
    vector<int> path;
    int cur = t;
    while (cur > 0) {
        int used = cur - par[cur];
        path.push_back(used);
        cur = par[cur];
    }

    reverse(path.begin(), path.end());
    for (int x : path) cout << x << " ";
    cout << "\n";

    return 0;
}
