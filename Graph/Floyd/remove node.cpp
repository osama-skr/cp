int main() {
    Meligy;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>dis[i][j];
        }
    }
    ll a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        a[i]--;
    }
    bool vis[n];
    memset(vis,0,sizeof(vis));
    vector<ll>ansx;
    for(int ix=n-1;ix>=0;ix--){
        vis[a[ix]]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dis[i][a[ix]]<INF&&dis[a[ix]][j]<INF)dis[i][j]=min(dis[i][j],dis[i][a[ix]]+dis[a[ix]][j]);
            }
        }
        ll ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(vis[i]&&vis[j]){
                    ans+=dis[i][j];
                }
            }
        }
        ansx.push_back(ans);
    }
    for(int i=n-1;i>=0;i--)cout<<ansx[i]<<" ";
    return 0;
}
