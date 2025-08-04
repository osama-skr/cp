//what is the minimum price of such a route?
//how many minimum-price routes are there? (modulo 1e9+7)
//what is the minimum number of flights in a minimum-price route?
//what is the maximum number of flights in a minimum-price route?
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>>q;
    ll c[n+1],maxx[n+1];
    vector<ll>minn(n+1,LLONG_MAX);
    vector<ll>dis(n+1,LLONG_MAX);
    memset(c,0,sizeof(c));
    memset(maxx,0,sizeof(maxx));
    q.push({0ll,s});
    dis[s]=minn[s]=maxx[s]=0;
    c[s]=1;
    while(!q.empty()){
        auto[d,a]=q.top();
        q.pop();
        if(d>dis[a])continue;
        for(auto[aa,dd]:adj[a]){
            if(dd+d<dis[aa]){
                minn[aa]=minn[a]+1;
                maxx[aa]=maxx[a]+1;
                dis[aa]=dd+d;
                c[aa]=c[a];
                q.push({d+dd,aa});
            }
            else if(dd+d==dis[aa]){
                minn[aa]=min(minn[aa],minn[a]+1);
                maxx[aa]=max(maxx[aa],maxx[a]+1);
                c[aa]=((c[aa]%mod)+(c[a]%mod))%mod;
            }
        }
    }
    cout<<dis[n]<<" "<<c[n]<<" "<<minn[n]<<" "<<maxx[n];
