//O(log(n))
vector<pair<ll, int>> factorize_lpf(ll n) {
    vector<pair<ll, int>> res;
    while (n > 1) {
        ll p = lpf[n];
        int cnt = 0;
        while (n % p == 0) {
            n /= p;
            cnt++;
        }
        res.emplace_back(p, cnt);
    }
    return res;
}
