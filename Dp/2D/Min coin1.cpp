#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e6 + 7;
const int mod = 1e9 + 7;
ll dp[N];
int par[N]; // لتتبع المسار

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t;
    cin >> n >> t;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    const ll INF = 1e18;
    fill(dp, dp + t + 1, INF);
    dp[0] = 0;
    par[0] = -1;

    for (int i = 1; i <= t; i++) {
        for (int j = 0; j < n; j++) {
            if (i - a[j] >= 0 && dp[i - a[j]] + 1 < dp[i]) {
                dp[i] = dp[i - a[j]] + 1;
                par[i] = i - a[j];
            }
        }
    }

    if (dp[t] == INF) {
        cout << -1 << "\n";
        return 0;
    }

    cout << dp[t] << "\n"; // أقل عدد عناصر

    // بناء الحل (طباعة القيم المستخدمة)
    vector<int> path;
    int cur = t;
    while (cur > 0) {
        path.push_back(cur - par[cur]); // القيمة المستخدمة = الفرق
        cur = par[cur];
    }

    reverse(path.begin(), path.end());

    for (int x : path) cout << x << " ";
    cout << "\n";

    return 0;
}
