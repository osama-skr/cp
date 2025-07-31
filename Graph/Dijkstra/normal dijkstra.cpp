    vector<vector<pair<ll,ll>>>adj(n+1);
    for(int i=0;i<m;i++){
        ll x,y,v;
        cin>>x>>y>>v;
        adj[x].push_back({y,v});

    }
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q;
    vector<ll>dis(n+1,LLONG_MAX);
    dis[s]=0;
    q.push({0ll,s});
    while(!q.empty()){
        auto[d,a]=q.top();
        q.pop();
        if(d>dis[a])continue;
        for(auto[aa,dd]:adj[a]){
            if(d+dd<dis[aa]){
                dis[aa]=d+dd;
                q.push({dis[aa],aa});
            }
        }
    }
    for(int i=1;i<=n;i++)cout<<dis[i]<<" ";
