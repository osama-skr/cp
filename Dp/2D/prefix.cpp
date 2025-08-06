#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int grid[N][N], pref[N][N];

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            pref[i][j] = grid[i][j];
            if(i > 0) pref[i][j] += pref[i-1][j];
            if(j > 0) pref[i][j] += pref[i][j-1];
            if(i > 0 && j > 0) pref[i][j] -= pref[i-1][j-1];
        }
    }

    // استعلام على مستطيل من (x1, y1) إلى (x2, y2)
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int sum = pref[x2][y2];
    if (x1 > 0) sum -= pref[x1 - 1][y2];
    if (y1 > 0) sum -= pref[x2][y1 - 1];
    if (x1 > 0 && y1 > 0) sum += pref[x1 - 1][y1 - 1];

    cout << sum << "\n";
}
