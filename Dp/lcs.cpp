#include <bits/stdc++.h>
using namespace std;

// Function to find the LCS and return it
string longest_common_subsequence(string A, string B) {
    int n = A.size(), m = B.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Fill DP table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (A[i - 1] == B[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Reconstruct LCS from DP table
    int i = n, j = m;
    string lcs = "";
    while (i > 0 && j > 0) {
        if (A[i - 1] == B[j - 1]) {
            lcs += A[i - 1];
            --i, --j;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }
    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main() {
    string A = "abcde";
    string B = "ace";
    string lcs = longest_common_subsequence(A, B);

    cout << "LCS length: " << lcs.size() << "\n";
    cout << "LCS: " << lcs << "\n";

    return 0;
}
