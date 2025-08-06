#include<bits/stdc++.h>
using namespace std;

const int N = 505;
const int MAX_VAL = 1001;

int a[N][N];
int freq[MAX_VAL][N][N]; // freq[val][i][j] = عدد مرات val من (0,0) إلى (i,j)

int n, m;

// بناء مصفوفة الترددات
void build_freq() {
    for (int val = 0; val < MAX_VAL; val++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                freq[val][i][j] = (a[i][j] == val);
                if (i > 0) freq[val][i][j] += freq[val][i - 1][j];
                if (j > 0) freq[val][i][j] += freq[val][i][j - 1];
                if (i > 0 && j > 0) freq[val][i][j] -= freq[val][i - 1][j - 1];
            }
        }
    }
}

// استعلام: كم مرة يظهر val في المستطيل (x1,y1) → (x2,y2)
int get_freq(int val, int x1, int y1, int x2, int y2) {
    int res = freq[val][x2][y2];
    if (x1 > 0) res -= freq[val][x1 - 1][y2];
    if (y1 > 0) res -= freq[val][x2][y1 - 1];
    if (x1 > 0 && y1 > 0) res += freq[val][x1 - 1][y1 - 1];
    return res;
}

int main() {
    cin >> n >> m;
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    build_freq();

    // مثال: استعلام واحد
    int val, x1, y1, x2, y2;
    cin >> val >> x1 >> y1 >> x2 >> y2;
    cout << get_freq(val, x1, y1, x2, y2) << "\n";

    return 0;
}
