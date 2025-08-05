#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define Meligy ios_base::sync_with_stdio(false); cin.tie(NULL);
ll mod=1e9 + 7;
const int N=20;
ll dp[1<<N][N];
int a[N][N];
int n;
ll rec(int mask,int i){
    if(__builtin_popcount(mask)==(n-2))return a[i][n-1];
    ll&ret=dp[mask][i];
    if(~ret)return ret;
    ret=0;
    for(int j=1;j<n-1;j++){
        if((mask>>(j-1))&1)continue;
        ret+=rec(mask|(1<<(j-1)),j)*a[i][j];
        ret%=mod;
    }
    return ret;
}
signed main(){
    Meligy
    cin>>n;
    int m;
    cin>>m;
    memset(a,0,sizeof(a));
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        x--;y--;
        a[x][y]++;
    }
    memset(dp,-1,sizeof(dp));
    ll ans=rec(0,0);
    cout<<ans<<"\n";
}
