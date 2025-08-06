#include<bits/stdc++.h>
using namespace std;
#define int long long
#define Meligy ios::sync_with_stdio(false); cin.tie(NULL);
int z;
struct dsu{
    vector<int>par,sz,v;
    dsu(int n){
        par.resize(n+1);
        v.resize(n+1,0);
        sz.assign(n+1,1);
        for(int i=0;i<=n;i++)par[i]=i;
    }

    int f(int x){
        if(par[x]==x)return x;
        return f(par[x]);
    }
    /*  faster if no sum
    int f(int x){
        if(par[x]==x)return x;
        return par[x]=f(par[x]);
    }
    */
    void mrg(int x,int y){
        x=f(x);
        y=f(y);
        if(x==y)return;
        if(sz[x]<sz[y])swap(x,y);
        par[y]=x;
        v[y]-=v[x];
        sz[x]+=sz[y];
    }
    void add(int x,int y){
        x=f(x);
        v[x]+=y;
    }
    int get(int x){
        int ans=0;
        while(par[x]!=x){
            ans+=v[x];
            x=par[x];
        }
        ans+=v[x];
        return ans;
    }
    void reset(int n) {
        for(int i=0;i<=n;i++) {
            par[i]=i;
            v[i]=0;
            sz[i]=1;
        }
    }
};

// To be,or not to be,that is the question
signed main() {
    int n,m;
    cin>>n>>m;
    z=n;
    dsu d(n);
    while(m--){
        string s;
        cin>>s;
        if(s[0]=='a'){
            int x,y;
            cin>>x>>y;
            d.add(x,y);
        }
        else if(s[0]=='j'){
            int x,y;
            cin>>x>>y;
            d.mrg(x,y);
        }
        else{
            int x;
            cin>>x;
            int ans=d.get(x);
            cout<<ans<<"\n";
        }
    }
    return 0;
}
