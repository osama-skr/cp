#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define Meligy ios_base::sync_with_stdio(false); cin.tie(NULL);
ll mod=1e9 + 7;
string s;
int n,d;
const int N=20;
ll dp[10004][100][2];
ll rec(int i,int sm,int f){
    if(i==n){
        return(sm==0);
    }
    ll &ret=dp[i][sm][f];
    if(~ret)return ret;
    int ls=9;
    if(f==1)ls=s[i]-'0';
    ret=0;
    for(int j=0;j<=ls;j++){
        ret+=rec(i+1,(sm+j)%d,(f==1)&&(j==ls));
        ret%=mod;
    }
    return ret;
}
int main(){
    Meligy
    cin>>s>>d;
    n=s.size();
    memset(dp,-1,sizeof(dp));
    ll ans=rec(0,0,1);
    cout<<((ans-1)+mod)%mod;//from 1 to s
}
