#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define Meligy ios_base::sync_with_stdio(false); cin.tie(NULL);
ll mod=1e9 + 7;
string a,b;
int n,k;
int d[11];
const int N=20;
ll dp[11][100][100][2];

ll rec(int i,int sm,int s,int f) {
    if(i==n)return (sm==0&&s==0);
    ll &ret=dp[i][sm][s][f];
    if(~ret)return ret;
    int ls=9;
    if(f==1)ls=b[i]-'0';
    ret=0;
    for(int j=0;j<=ls;j++){
        ret+=rec(i+1,((sm*10)+j)%k,(s+j)%k,f&&(j==ls));
    }
    return ret;
}
int main(){
    Meligy
    int t;
    cin>>t;
    for(int tt=1;tt<=t;tt++){
        cout<<"Case "<<tt<<": ";
        memset(dp,-1,sizeof(dp));
        cin>>a>>b>>k;
        if(k>100){
            cout<<0<<"\n";
            continue;
        }
        n=b.size();
        ll ans=rec(0,0,0,1);
        memset(dp,-1,sizeof(dp));
        if(a!="0"){
            int j=a.size()-1;
            while(a[j]=='0'){
                a[j]='9';
                j--;
            }
            if(j>=0)a[j]=(((a[j]-'0')-1)+'0');
        }
        swap(a,b);
        n=b.size();
        ll anss=rec(0,0,0,1);
        cout<<ans-anss<<"\n";
    }
}
