//For Longest Palindromic Substring in O(n)

string preprocess(const string &s) {
    string t = "#";
    for (char c : s) {
        t += c;
        t += "#";
    }
    return t;
}
string longestPalindrome(string s) {
    string t = preprocess(s);
    int n = t.size();
    vector<int> P(n, 0);
    int C = 0, R = 0;
    for (int i = 0; i < n; i++) {
        int mirror = 2*C - i;
        if (i < R)
            P[i] = min(R - i, P[mirror]);
        // Try to expand palindrome centered at i
        while (i + P[i] + 1 < n && i - P[i] - 1 >= 0 && t[i + P[i] + 1] == t[i - P[i] - 1])
            P[i]++;
        // Update center and right boundary
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }
    // Find the max in P
    int maxLen = 0, center = 0;
    for (int i = 0; i < n; i++) {
        if (P[i] > maxLen) {
            maxLen = P[i];
            center = i;
        }
    }
    int start = (center - maxLen) / 2; // remove '#' effect
    return s.substr(start, maxLen);
}