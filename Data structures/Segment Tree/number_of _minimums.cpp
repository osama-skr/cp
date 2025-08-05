#include <bits/stdc++.h>
using namespace std;
int sz;
vector<pair<int,int>>mins;
vector<int>v;
pair<int,int> cmp(pair<int,int>a,pair<int,int>b){
    if(a.first<b.first)return a;
    if(a.first>b.first)return b;
    return {a.first,a.second+b.second};
}
void upd(int idx, int val, int node, int l, int r){
    if(l==r)mins[node]={val,1};
    else{
        int mid=(l+r)/2;
        if(idx<=mid)upd(idx,val,node*2+1,l,mid);
        else upd(idx,val,node*2+2,mid+1,r);
        mins[node]=cmp(mins[node*2+1],mins[node*2+2]);
    }
}
void upde(int idx, int val){
    upd(idx,val,0,0,sz);
}
pair<int,int> qer(int st, int nd, int node, int l, int r){
    if(r<st||l>nd)return {INT_MAX,0};
    if(l>=st&&r<=nd)return mins[node];
    int mid=(l+r)/2;
    return cmp(qer(st,nd,node*2+1,l,mid),qer(st,nd,node*2+2,mid+1,r));
}
pair<int,int> qere(int l,int r){
    return qer(l,r,0,0,sz);
}
signed main()
{
    int n,m,lg;cin>>n>>m;
    lg=log2(n);
    if((int)pow(2,lg)!=n)lg++;
    sz=pow(2,lg);
    v.assign(sz,INT_MAX);
    sz--;
    mins.resize(pow(2,lg+1)-1);
    for(int i=0;i<n;i++){
        cin>>v[i];
        upde(i,v[i]);
    }
    while(m--){
        int num;cin>>num;
        if(num==1){
            int i, u;cin>>i>>u;
            upde(i,u);
        }
        else{
            int l,r;cin>>l>>r;
            auto thing=qere(l,r-1);
            cout<<thing.first<<' '<<thing.second<<'\n';
        }
    }

    return 0;
}