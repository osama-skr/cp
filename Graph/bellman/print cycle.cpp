int main(){
    Meligy
    ll n,m;
    cin>>n>>m;
    ll s=1;
    ll edg[m][3];
    for(int i=0;i<m;i++){
        cin>>edg[i][0]>>edg[i][1]>>edg[i][2];
        edg[i][0]--;
        edg[i][1]--;
    }
    vector<ll>dis(n,0),p(n,-1);
    int c=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ll x=edg[j][0],y=edg[j][1],z=edg[j][2];
            if(dis[y]>dis[x]+z){
                dis[y]=dis[x]+z;
                if(i==n-1)c=y;
                p[y]=x;
            }
        }
    }
    if(c==-1)cout<<"NO";
    else{
        cout<<"YES\n";
        for(int i=0;i<n;i++)c=p[c];
        vector<ll>cyc;
        for(int i=c;i!=c||cyc.size()==0;i=p[i])cyc.push_back(i);
        cyc.push_back(c);
        for(int i=cyc.size()-1;i>=0;i--)cout<<cyc[i]+1<<" ";
    }

}
