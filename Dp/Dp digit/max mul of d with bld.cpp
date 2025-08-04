#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define Meligy ios_base::sync_with_stdio(false); cin.tie(NULL);
ll mod=1e9 + 7;
string a,b;
int n,k;
int d[11];
const int N=20;
ll dp[20][2][2][2];
ll maxx=0;
ll rec(int i,int f,int z,int y) {
    if(i==n){
        return 1;
    }
    ll &ret=dp[i][f][z][y];
    if(~ret)return ret;
    int ls=9,fs=0;
    if(f==1)ls=b[i]-'0';
    if(z==1)fs=a[i]-'0';

    ret=0;
    for(int j=fs;j<=ls;j++){
        if(j==0&&y)ret=max(ret,rec(i+1,f&&(j==ls),z&&(j==fs),1));
        else ret=max(ret,j*rec(i+1,f&&(j==ls),z&&(j==fs),0));
    }
    return ret;
}
bool fx=0;
void build(int i,int f,int z,int y) {
    if(i==n){
        return ;
    }
    int ls=9,fs=0;
    if(f==1)ls=b[i]-'0';
    if(z==1)fs=a[i]-'0';

    ll maxx=0;
    char cur='0';
    for(int j=fs;j<=ls;j++){
        int x=j;
        if(y&&x==0)x++;
        ll v=0;
        if(j==0&&y)v=rec(i+1,f&&(j==ls),z&&(j==fs),1);
        else v=j*rec(i+1,f&&(j==ls),z&&(j==fs),0);
        if(dp[i][f][z][y]==v){
            if(j>0)fx=1;
            if(fx)cout<<j;
            build(i+1,f&&(j==ls),z&&(j==fs),(j==0&&y));
            return;
        }
    }
}
int main(){
    Meligy
    memset(dp,-1,sizeof(dp));
    cin>>a>>b;
    n=b.size();
    while(a.size()<b.size())a='0'+a;
    ll ans=rec(0,1,1,1);
    build(0,1,1,1);
}
