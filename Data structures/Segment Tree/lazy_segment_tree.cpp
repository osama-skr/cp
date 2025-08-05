#include <bits/stdc++.h>
using namespace std;
vector<int> v;
vector<int> sums, lazy;
int sz;
void push(int node, int l, int r) {
    if (lazy[node] != 0) {
        sums[node] += (r - l + 1) * lazy[node];  // Apply lazy to current node
        if (l != r) { // Not a leaf node
            lazy[node * 2 + 1] += lazy[node];   // Push to left child
            lazy[node * 2 + 2] += lazy[node];   // Push to right child
        }
        lazy[node] = 0;
    }
}
void init(int node, int l, int r) {
    if (l == r) {
        sums[node] = v[l];
    } else {
        int mid = (l + r) / 2;
        init(node * 2 + 1, l, mid);
        init(node * 2 + 2, mid + 1, r);
        sums[node] = sums[node * 2 + 1] + sums[node * 2 + 2];
    }
}
void range_update(int node, int l, int r, int st, int nd, int val) {
    push(node, l, r);
    if (r < st || l > nd) return;
    if (l >= st && r <= nd) {
        lazy[node] += val;
        push(node, l, r);
        return;
    }
    int mid = (l + r) / 2;
    range_update(node * 2 + 1, l, mid, st, nd, val);
    range_update(node * 2 + 2, mid + 1, r, st, nd, val);
    sums[node] = sums[node * 2 + 1] + sums[node * 2 + 2];
}
int range_query(int node, int l, int r, int st, int nd) {
    push(node, l, r);
    if (r < st || l > nd) return 0;
    if (l >= st && r <= nd) return sums[node];
    int mid = (l + r) / 2;
    return range_query(node * 2 + 1, l, mid, st, nd)
         + range_query(node * 2 + 2, mid + 1, r, st, nd);
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    int lg = log2(n);
    if ((int)pow(2, lg) != n) lg++;
    v.resize(pow(2, lg));
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = n; i < pow(2, lg); i++) v[i] = 0;

    int full_size = 2 * pow(2, lg) - 1;
    sums.resize(full_size);
    lazy.resize(full_size);
    sz = pow(2, lg) - 1;

    init(0, 0, sz);
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r, val;
            cin >> l >> r >> val;  // Add val to [l, r-1]
            range_update(0, 0, sz, l, r - 1, val);
        } else {
            int l, r;
            cin >> l >> r;  // Query sum in [l, r-1]
            cout << range_query(0, 0, sz, l, r - 1) << '\n';
        }
    }

    return 0;
}
