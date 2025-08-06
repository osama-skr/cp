#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int p = 31;          // base prime
const int mod = 1e9 + 9;   // large prime
vector<int> rabin_karp(const string &text, const string &pattern) {
    int n = text.size(), m = pattern.size();
    vector<ll> p_pow(max(n, m));
    p_pow[0] = 1;
    for (int i = 1; i < (int)p_pow.size(); i++)
        p_pow[i] = (p_pow[i-1] * p) % mod;
    // Compute hash of pattern
    ll pat_hash = 0;
    for (int i = 0; i < m; i++)
        pat_hash = (pat_hash + (pattern[i] - 'a' + 1) * p_pow[i]) % mod;
    // Compute prefix hashes of text
    vector<ll> h(n + 1, 0);
    for (int i = 0; i < n; i++)
        h[i+1] = (h[i] + (text[i] - 'a' + 1) * p_pow[i]) % mod;
    vector<int> positions;
    for (int i = 0; i + m - 1 < n; i++) {
        ll curr_hash = (h[i + m] - h[i] + mod) % mod;
        if (curr_hash == (pat_hash * p_pow[i]) % mod)
            positions.push_back(i);
    }
    return positions;
}
int main() {
    string text = "ababcabcababc";
    string pattern = "abc";
    vector<int> matches = rabin_karp(text, pattern);
    for (int idx : matches)
        cout << "Pattern found at index: " << idx << '\n';
    return 0;
}