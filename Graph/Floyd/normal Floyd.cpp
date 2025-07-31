const ll INF=1e18;
const int N=507;

ll dis[N][N];
bool neg(int n) {
    for(int i=0;i<n;i++){
        if(dis[i][i]<0)return 1;
    }
    return 0;
}

int main() {
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)dis[i][j]=0;
            else dis[i][j]=INF;
        }
    }
    for(int i=0;i<m;i++){
        ll x,y,w;
        cin>>x>>y>>w;
        x--;
        y--;
        dis[x][y]=min(dis[x][y],w);
        dis[y][x]=min(dis[y][x],w);
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dis[i][k]<INF&&dis[k][j]<INF)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        ll x,y;
        cin>>x>>y;
        x--;
        y--;
	      bool f=0;
      	for(int i=0;i<n;i++){
            if(dis[i][i]<0&&dis[x][i]<INF&&dis[i][y]<INF)f=1;
        }
        if(f)cout<<"INF\n";
        if(dis[x][y]==INF)cout<<-1<<"\n";
        else cout<<dis[x][y]<<"\n";
    }

    return 0;
}
