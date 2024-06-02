#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll N=10005;
vector<pair<ll,ll>> g[N],v[N];
vector<tuple<ll,ll,ll>> g2[N];
ll dp1[N],dp2[N];
bool vis[N];

void dfs (ll nn,ll b){
    vis[nn]=1;
    for (auto [xn,xw,xi]:g2[nn]){
        if (b&1<<xi && !vis[xn]){
            dfs(xn,b);
            v[nn].emplace_back(xn,xw);
            dp1[nn]+=dp2[xn];
        }
    }
    for (auto [xn,xw]:g[nn]){
        if (!vis[xn]) {
            dfs(xn,b);
            v[nn].emplace_back(xn,xw);
            dp1[nn]+=dp2[xn];
        }
    }
    dp2[nn]=dp1[nn];
    if(g2[nn].size() == 0) {
      for (auto [xn,xw]:v[nn]){
          dp2[nn]=max(dp2[nn],dp1[xn]+dp1[nn]-dp2[xn]+xw);
      }
    }
	else {
		dp2[nn] = dp1[nn];
		dp1[nn] = -1e9 - 100;
	}
	cerr << dp1[nn] << " " << dp2[nn] << "\n";
    v[nn].clear();
    return;
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,k,ans=0;
    cin >> n >> k;
    for (ll i=1;i<n;i++){
        ll u,v,w;
        cin >> u >> v >> w;
        g[u].emplace_back(v,w);
        g[v].emplace_back(u,w);
    }
    for (ll i=0;i<k;i++){
        ll u,v,w;
        cin >> u >> v >> w;
        g2[u].emplace_back(v,w,i);
        g2[v].emplace_back(u,w,i);
    }
    for (ll i=0;i<1<<k;i++){
        for (ll j=1;j<=n;j++) vis[j]=dp1[j]=dp2[j]=0;
        dfs(1,i);
        ans=max({ans,dp1[1],dp2[1]});
    }
    cout << ans;
}
