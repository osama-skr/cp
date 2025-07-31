int main() {
    int n,q;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>dis[i][j];
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dis[i][k]<INF&&dis[k][j]<INF)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    cin>>q;
    while(q--){
        ll x,y,c;
        cin>>x>>y>>c;
        x--;
        y--;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ll c1=dis[i][x]+dis[y][j]+c;
                ll c2=dis[i][y]+dis[x][j]+c;
                dis[i][j]=min(dis[i][j],min(c1,c2));
            }
        }
    }
    return 0;
}
