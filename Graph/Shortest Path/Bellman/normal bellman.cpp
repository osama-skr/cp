#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define Meligy ios_base::sync_with_stdio(false); cin.tie(NULL);
int main(){
    ll n,m,q,s;
    cin>>n>>m>>q>>s;
    ll edg[m][3];
    for(int i=0;i<m;i++){
        cin>>edg[i][0]>>edg[i][1]>>edg[i][2];
    }
    vector<ll>dis(n,1e18);
    dis[s]=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m;j++){
            ll x=edg[j][0],y=edg[j][1],z=edg[j][2];
            if(dis[x]<1e18&&dis[y]>dis[x]+z){
                dis[y]=dis[x]+z;
            }
        }
    }
    ll minn=-1e18;
    vector<bool>cyc(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ll x=edg[j][0],y=edg[j][1],z=edg[j][2];
            if(dis[x]<1e18&&dis[y]>dis[x]+z){
                dis[y]=minn;
                cyc[y]=1;
            }
        }
    }
    while(q--){
        int e;
        cin>>e;
        if(cyc[e])cout<<"-Infinity\n";
        else if(dis[e]==1e18)cout<<"Impossible\n";
        else cout<<dis[e]<<"\n";
    }
    cout<<"\n";
}
