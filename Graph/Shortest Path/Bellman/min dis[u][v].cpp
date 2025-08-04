int main(){
    Meligy
    int t;
    cin>>t;
    while(t--){
    ll n,m;
    cin>>n>>m;
    ll edg[m][3];
    ll mn=1e18;
    for(int i=0;i<m;i++){
        cin>>edg[i][0]>>edg[i][1]>>edg[i][2];
        edg[i][0]--;
        edg[i][1]--;
        mn=min(mn,edg[i][2]);
    }
    if(mn>=0){
        cout<<mn<<"\n";
        continue;
    }
    vector<ll>dis(n,0);
    int c=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ll x=edg[j][0],y=edg[j][1],z=edg[j][2];
            if(dis[y]>dis[x]+z){
                dis[y]=dis[x]+z;
                if(i==n-1)c=y;
            }
        }
    }
    mn=0;
    for(int i=0;i<n;i++)mn=min(mn,dis[i]);
    if(c!=-1)cout<<"-inf\n";
    else{
        cout<<mn<<"\n";
    }
    }

} 
