#include <bits/stdc++.h>
using namespace std;

// Function to find the actual Longest Increasing Subsequence
vector<int> longest_increasing_subsequence(vector<int>& nums) {
    int n = nums.size();
    vector<int> tail_idx;       // Stores indices of potential LIS ends
    vector<int> prev(n, -1);    // To reconstruct the path

    for (int i = 0; i < n; ++i) {
        int x = nums[i];
        // Binary search in tail_idx to find first element >= x
        int l = 0, r = tail_idx.size();
        while (l < r) {
            int m = (l + r) / 2;
            if (nums[tail_idx[m]] < x)
                l = m + 1;
            else
                r = m;
        }

        // Update prev[i] to point to the last element of the previous LIS
        if (l > 0)
            prev[i] = tail_idx[l - 1];

        // Extend or replace in tail_idx
        if (l == tail_idx.size())
            tail_idx.push_back(i);
        else
            tail_idx[l] = i;
    }

    // Reconstruct the sequence
    vector<int> lis;
    int idx = tail_idx.back();
    while (idx != -1) {
        lis.push_back(nums[idx]);
        idx = prev[idx];
    }
    reverse(lis.begin(), lis.end());
    return lis;
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    vector<int> lis = longest_increasing_subsequence(nums);

    cout << "Length of LIS: " << lis.size() << "\n";
    cout << "LIS sequence: ";
    for (int x : lis) cout << x << " ";
    cout << "\n";

    return 0;
}
