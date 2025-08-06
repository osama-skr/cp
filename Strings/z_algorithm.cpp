//find all occurrences of a pattern inside a text in O(n)
//##################################################

#include <bits/stdc++.h>
using namespace std;
// Function to compute Z-array
vector<int> computeZ(string s) {
    int n = s.length();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]); // reuse previously computed values
        // expand the match
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        // update the Z-box
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}
// Pattern matching using Z-algorithm
vector<int> zPatternMatch(string pattern, string text) {
    string concat = pattern + "$" + text;
    vector<int> z = computeZ(concat);
    vector<int> result;
    for (int i = pattern.length() + 1; i < z.size(); i++) {
        if (z[i] == pattern.length()) {
            result.push_back(i - pattern.length() - 1); // match found at this index
        }
    }
    return result;
}
int main() {
    string text = "ababcababcab";
    string pattern = "ab";
    vector<int> matches = zPatternMatch(pattern, text);
    for (int idx : matches)
        cout << "Pattern found at index: " << idx << '\n';
    return 0;
}
