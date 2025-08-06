#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
const int N = 1e6 + 7;
const int mod = 1e9 + 7;
ll dp[N];
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n,t;
    cin>>n>>t;
    ll a[n];
    for(int i=0;i<n;i++)cin>>a[i];
 
    dp[0]=0;
    for(int i=1;i<=t;i++) {
        dp[i]=INT_MAX;
        for(int j=0;j<n;j++) {
            if (i-a[j]>=0) {
                dp[i]=min(dp[i],1+dp[i-a[j]]);
            }
        }
    }
    if(dp[t]==INT_MAX){
        cout<<-1;
        return 0;
    }
    cout<<dp[t];
