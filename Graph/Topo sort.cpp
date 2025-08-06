#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define Meligy ios_base::sync_with_stdio(false); cin.tie(NULL);

const int N=200005;
vector<ll>adj[N];
bool vis[N];
void dfs(int s,stack<int> &st){
    vis[s]=1;
    for(auto u:adj[s]){
        if(!vis[u])dfs(u,st);
    }
    st.push(s);
}

int main() {
    Meligy
    ll n,m;
    cin>>n>>m;
    bool f=0;
    if(n==0&&m==0)return 0;
    ll a,b;
    vector<int>deg(n+1,0);
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        deg[b]++;
        adj[a].push_back(b);
    }
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i=1;i<=n;i++) {
        if(deg[i]==0){
            q.push(i);
        }
    }
    vector<int>ans;
    while(!q.empty()){
        if(q.size()>1)f=1;
        int node=q.top();
        q.pop();
        ans.push_back(node);
        for(auto it : adj[node]){
            deg[it]--;
            if(deg[it]==0){
                q.push(it);
                if(q.size()>1)f=1;
            }
        }
    }
    if(!f)cout<<"Unique\n";
    if(ans.size()!=n)cout<<"No\n";
    else{
        cout<<"Yes\n";
        for(int i=0;i<n;i++)cout<<ans[i]<<" ";
    }
    return 0;
}
