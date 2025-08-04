    priority_queue<pair<pair<ll,ll>,bool>,vector<pair<pair<ll,ll>,bool>>,greater<>>q;
    vector<vector<ll>>dis(n+1,vector<ll>(2,LLONG_MAX));
    dis[s][0]=0;
    q.push({{0ll,s},0});
    while(!q.empty()){
        auto[i,f]=q.top();
        ll d=i.first,a=i.second;
        q.pop();
        if(d>dis[a][f])continue;
        for(auto[aa,dd]:adj[a]){
            if(d+dd<dis[aa][f]){
                dis[aa][f]=d+dd;
                q.push({{dis[aa][f],aa},f});
            }
            if(!f && d+(dd/2)<dis[aa][1]){
                dis[aa][1]=d+(dd/2);
                q.push({{dis[aa][1],aa},1});
            }
        }
    }
    cout<<dis[n][1];
