typedef long long ll;
const int p = 31;
const int mod = 1e9 + 9;
vector<ll> p_pow, h;
// Precompute p^i and prefix hashes
void build_hash(const string &s) {
    int n = s.size();
    p_pow.resize(n);
    h.resize(n + 1);

    p_pow[0] = 1;
    for (int i = 1; i < n; i++)
        p_pow[i] = (p_pow[i-1] * p) % mod;

    h[0] = 0;
    for (int i = 0; i < n; i++)
        h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % mod;
}
// Get hash of s[l...r] in O(1)
ll get_hash(int l, int r) {
    ll res = (h[r+1] - h[l] + mod) % mod;
    res = (res * p_pow[p_pow.size() - l - 1]) % mod;
    return res;
}