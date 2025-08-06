#include <bits/stdc++.h>
using namespace std;
struct FenwickTree {
    int n;
    vector<long long> bit;
    FenwickTree(int size) {
        n = size;
        bit.assign(n + 1, 0);  // 1-based index
    }
    // Add 'val' to index 'i'
    void add(int i, long long val) {
        while (i <= n) {
            bit[i] += val;
            i += i & -i;
        }
    }
    // Prefix sum from 1 to i
    long long sum(int i) {
        long long res = 0;
        while (i > 0) {
            res += bit[i];
            i -= i & -i;
        }
        return res;
    }
    // Range sum from l to r (inclusive)
    long long range_sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};
int main() {
    int n = 10;
    FenwickTree ft(n);
    ft.add(3, 5);  // a[3] += 5
    ft.add(7, 2);  // a[7] += 2
    cout << ft.sum(7) << "\n";        // sum(1..7)
    cout << ft.range_sum(3, 7) << "\n"; // sum(3..7)
    return 0;
}
