#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// Use two different base primes and two different large mod primes
const int P1 = 31, P2 = 37;
const int MOD1 = 1e9 + 7, MOD2 = 1e9 + 9;
vector<int> rabin_karp_double_hash(const string &text, const string &pattern) {
    int n = text.size(), m = pattern.size();
    vector<ll> p_pow1(max(n, m)), p_pow2(max(n, m));
    p_pow1[0] = p_pow2[0] = 1;
    for (int i = 1; i < max(n, m); i++) {
        p_pow1[i] = (p_pow1[i-1] * P1) % MOD1;
        p_pow2[i] = (p_pow2[i-1] * P2) % MOD2;
    }
    // Compute hash of pattern for both hashes
    ll pat_hash1 = 0, pat_hash2 = 0;
    for (int i = 0; i < m; i++) {
        pat_hash1 = (pat_hash1 + (pattern[i] - 'a' + 1) * p_pow1[i]) % MOD1;
        pat_hash2 = (pat_hash2 + (pattern[i] - 'a' + 1) * p_pow2[i]) % MOD2;
    }
    // Compute prefix hashes of text for both hashes
    vector<ll> h1(n + 1, 0), h2(n + 1, 0);
    for (int i = 0; i < n; i++) {
        h1[i + 1] = (h1[i] + (text[i] - 'a' + 1) * p_pow1[i]) % MOD1;
        h2[i + 1] = (h2[i] + (text[i] - 'a' + 1) * p_pow2[i]) % MOD2;
    }
    vector<int> positions;
    for (int i = 0; i + m <= n; i++) {
        ll curr_hash1 = (h1[i + m] - h1[i] + MOD1) % MOD1;
        ll curr_hash2 = (h2[i + m] - h2[i] + MOD2) % MOD2;
        // Scale the pattern hash to current index
        ll scaled_pat_hash1 = (pat_hash1 * p_pow1[i]) % MOD1;
        ll scaled_pat_hash2 = (pat_hash2 * p_pow2[i]) % MOD2;
        if (curr_hash1 == scaled_pat_hash1 && curr_hash2 == scaled_pat_hash2)
            positions.push_back(i);
    }
    return positions;
}
int main() {
    string text = "ababcabcababc";
    string pattern = "abc";
    vector<int> matches = rabin_karp_double_hash(text, pattern);
    for (int idx : matches)
        cout << "Pattern found at index: " << idx << '\n';
    return 0;
}
