#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int W = 1e4 + 5;

int dp[N][W];         // dp[i][w] = max value using first i items with capacity w
bool take[N][W];      // take[i][w] = did we take item i?

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, maxW;
    cin >> n >> maxW;

    vector<int> wt(n), val(n);
    for(int i = 0; i < n; i++) cin >> wt[i] >> val[i];

    for(int i = 1; i <= n; i++) {
        for(int w = 0; w <= maxW; w++) {
            // Don't take item i-1
            dp[i][w] = dp[i-1][w];

            // Try to take it
            if(w >= wt[i-1]) {
                int newVal = dp[i-1][w - wt[i-1]] + val[i-1];
                if(newVal > dp[i][w]) {
                    dp[i][w] = newVal;
                    take[i][w] = true;
                }
            }
        }
    }

    // Result
    cout << "Maximum value = " << dp[n][maxW] << "\n";

    // Recovering items
    vector<int> items;
    int w = maxW;
    for(int i = n; i >= 1; i--) {
        if(take[i][w]) {
            items.push_back(i-1);  // item i-1 was taken
            w -= wt[i-1];
        }
    }

    reverse(items.begin(), items.end());

    cout << "Items chosen (0-based indices): ";
    for(int i : items) cout << i << " ";
    cout << "\n";
}
