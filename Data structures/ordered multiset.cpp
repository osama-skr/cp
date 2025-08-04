#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

using pii = pair<int,int>;
using ordered_multiset = tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update>;

ordered_multiset os;
int uid = 0; // unique incrementing id

// insert value x
void insert_val(int x) {
    os.insert({x, uid++});
}

// erase one occurrence of x (if any)
bool erase_one(int x) {
    auto it = os.lower_bound({x, -1}); // first with value x
    if (it != os.end() && it->first == x) {
        os.erase(it);
        return true;
    }
    return false;
}

// erase all occurrences of x
void erase_all(int x) {
    while (erase_one(x)) {}
}

// count of elements < x
int count_less(int x) {
    return os.order_of_key({x, -1});
}

// count of occurrences of x
int count_eq(int x) {
    return os.order_of_key({x+1, -1}) - os.order_of_key({x, -1});
}

// k-th smallest (0-based)
int kth(int k) {
    if (k < 0 || k >= (int)os.size()) throw runtime_error("out of bounds");
    return os.find_by_order(k)->first;
}
