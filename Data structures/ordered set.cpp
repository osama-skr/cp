#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef __gnu_pbds::tree<int,__gnu_pbds::null_type,less<int>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>ordered_set;

ordered_set os;
os.insert(x);                // O(log n)
os.erase(x);                 // O(log n)
*os.find_by_order(k);        // O(log n): get k-th smallest (0-based)
os.order_of_key(x);          // O(log n): count of elements < x
