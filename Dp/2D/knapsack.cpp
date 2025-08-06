#include <bits/stdc++.h>
using namespace std;

const int W = 1e5 + 5;
long long dp[W];

int main() {
    int n, maxWeight;
    cin >> n >> maxWeight;

    vector<int> weight(n), value(n);
    for(int i = 0; i < n; i++) cin >> weight[i] >> value[i];

    for(int i = 0; i < n; i++) {
        for(int w = maxWeight; w >= weight[i]; w--) {
            dp[w] = max(dp[w], dp[w - weight[i]] + value[i]);
        }
    }

    cout << dp[maxWeight] << "\n";
}
