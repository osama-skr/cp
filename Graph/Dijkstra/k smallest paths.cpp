    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>>q;
    vector<ll>ans;
    ll c[n+1];
    memset(c,0,sizeof(c));
    q.push({0ll,s});
    while(!q.empty()&&c[e]<k){
        auto[d,a]=q.top();
        c[a]++;
        q.pop();
        if(a==e)ans.push_back(d);
        if(c[a]>k)continue;
        for(auto[aa,dd]:adj[a]){
            if(c[aa]>k)continue;
            q.push({d+dd,aa});
        }
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<k;i++)cout<<ans[i]<<" ";
