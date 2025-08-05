#include <bits/stdc++.h>
using namespace std;

// O(n log n) optimized version using binary search
int longestIncreasingSubsequence(vector<int>& a) {
    vector<int> lis;

    for (int x : a) {
        // Find the index of the first element >= x
        auto it = lower_bound(lis.begin(), lis.end(), x);

        if (it == lis.end()) {
            // x is larger than any element, extend LIS
            lis.push_back(x);
        } else {
            // Replace to maintain a smaller end element
            *it = x;
        }
    }

    return lis.size();
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    cout << longestIncreasingSubsequence(a) << endl;
    return 0;
}
