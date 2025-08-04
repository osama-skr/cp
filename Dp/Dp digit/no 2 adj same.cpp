#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define Meligy ios_base::sync_with_stdio(false); cin.tie(NULL);
ll dp[20][11][2][2];
string a;
int n;
ll rec(int i,int d,bool f,bool s) {
    if(i==n){
        //if(!s)return 0;
        return 1;
    }
    ll &ret=dp[i][d][f][s];
    if(~ret)return ret;
    int ls=9;
    if(f==1)ls=a[i]-'0';
    ret=0;
    for(int j=0;j<=ls;j++){
        if(s&&j==d)continue;
        ret+=rec(i+1,j,f&&(j==ls),s||(j!=0));
    }
    return ret;
}
int main(){
    Meligy
    string l,r;
    cin>>l>>r;
    int c=0;
    if(l!="0"){
        int j=l.size()-1;
        while(l[j]=='0'){
            l[j]='9';
            j--;
        }
        if(j>=0)l[j]=(((l[j]-'0')-1)+'0');
    }
    else{
        c=1;
    }
    a=r;
    n=a.size();
    memset(dp,-1,sizeof(dp));
    ll ans=rec(0,10,1,0);
    a=l;
    n=a.size();
    memset(dp,-1,sizeof(dp));
    ll anss=rec(0,10,1,0);
    cout<<ans-(anss-c)<<"\n";
}
