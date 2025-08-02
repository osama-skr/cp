//O(sqrt(n))
vector<pair<ll, int>> factorize_trial(ll n) {
    vector<pair<ll, int>> res;
    for (ll p : primes) {
        if (p * p > n) break;
        if (n % p == 0) {
            int cnt = 0;
            while (n % p == 0) {
                n /= p;
                cnt++;
            }
            res.emplace_back(p, cnt);
        }
    }
    if (n > 1) res.emplace_back(n, 1);
    return res;
}
