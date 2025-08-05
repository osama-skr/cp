#include <bits/stdc++.h>
using namespace std;

// Function to compute length of LIS ending at each position
vector<int> get_lis_lengths(const vector<int>& nums) {
    int n = nums.size();
    vector<int> lis_len(n, 1);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < i; ++j)
            if (nums[j] < nums[i])
                lis_len[i] = max(lis_len[i], lis_len[j] + 1);
    return lis_len;
}

// Function to find the minimum lexicographical LIS
vector<int> min_lex_lis(const vector<int>& nums) {
    int n = nums.size();
    vector<int> lis_len = get_lis_lengths(nums);

    int len = *max_element(lis_len.begin(), lis_len.end());

    vector<int> result;
    int prev = INT_MIN;
    int need = len;

    for (int i = 0; i < n; ++i) {
        if (nums[i] > prev && lis_len[i] == need) {
            result.push_back(nums[i]);
            prev = nums[i];
            need--;
        }
    }

    return result;
}

int main() {
    vector<int> nums = {3, 5, 7, 1, 2, 8};
    vector<int> lis = min_lex_lis(nums);

    cout << "Min-Lex LIS length: " << lis.size() << "\n";
    cout << "Min-Lex LIS: ";
    for (int x : lis) cout << x << " ";
    cout << "\n";

    return 0;
}
