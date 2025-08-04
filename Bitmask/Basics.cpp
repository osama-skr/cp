// check i-th bit (0-indexed)
(mask >> i) & 1;

// set i-th bit to 1
mask |= (1 << i);

// set i-th bit to 0
mask &= ~(1 << i);

//(union)
maskA | maskB;

//(intersection)
maskA & maskB;

// number of set bits
__builtin_popcount(mask);           // int
__builtin_popcountll(mask);         // long long

// returns idx for first one from right (0-indexed)
__builtin_ctz(mask);                // int
__builtin_ctzll(mask);              // long long

// returns idx for first one from left (0-indexed)(if no mins = num of leading 0s)
31 - __builtin_clz(mask);            // int
63 - __builtin_clzll(mask);         // long long
