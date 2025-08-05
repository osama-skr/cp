#include <bits/stdc++.h>
using namespace std;
vector<int>v;
vector<int>sums;
int sz;
void init(int node, int l,int r){
    if(l==r){
        sums[node]=v[l];
    }
    else{
        int mid=(l+r)/2;
        init(node*2+1,l,mid);
        init(node*2+2,mid+1,r);
        sums[node]=sums[node*2+1]+sums[node*2+2];
    }
}
void upde(int node, int l,int r,int idx,int val){
    if(l==r){
        sums[node]=val;
    }
    else{
        int mid=(l+r)/2;
        if(idx<=mid)upde(node*2+1,l,mid,idx,val);
        else upde(node*2+2,mid+1,r,idx,val);
        sums[node]=sums[node*2+1]+sums[node*2+2];
    }
}
int qere(int st, int nd,int node,int l,int r ){
    if(l>nd||r<st)return 0;
    if(l>=st&&r<=nd)return sums[node];
    int mid=(l+r)/2;
    return qere(st,nd,node*2+1,l,mid)+qere(st,nd,node*2+2,mid+1,r);
}
int qer(int st,int nd){
    return qere(st,nd,0,0,sz);
}
void upd(int idx, int val){
    upde(0,0,sz,idx,val);
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;cin>>n>>m;
    int lg=log2(n);
    if((int)pow(2,lg)!=n)lg++;
    v.resize(pow(2,lg));
    for(int i=0;i<n;i++)cin>>v[i];
    for(int i=n;i<pow(2,lg);i++)v[i]=0;
    sums.resize(2*pow(2,lg)-1);
    sz=pow(2,lg)-1;
    init(0,0,sz);
    while(m--){
        int num;cin>>num;
        if(num==1){
            int i,v;cin>>i>>v;
            upd(i,v);
        }
        else{
            int l,r;cin>>l>>r;
            cout<<qer(l,r-1)<<'\n';
        }
    }

    return 0;
}