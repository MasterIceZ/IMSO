#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
  int n;
  cin >> n;
  vector<int> dia(n),dep(n);
  for(int i=0;i<n;i++){
    int m;
    cin >> m;
    vector<vector<int>> adj(m+2);
    for(int j=1;j<=m;j++){
      int p;
      cin >> p;
      adj[p].emplace_back(j);
      adj[j].emplace_back(p);
    }
    vector<int> d(m+2);
    function<void(int,int)> dfs=[&](int u,int p){
      for(auto v:adj[u])if(v!=p){
        d[v]=d[u]+1;
        dfs(v,u);
      }
    };
    d[0]=-1;
    dfs(0,-1);
    pair<int,int> mx(-1,0);
    for(int j=1;j<=m;j++)mx=max(mx,pair<int,int>(d[j],j));
    int rt;
    tie(dep[i],rt)=mx;
    d[rt]=0;
    dfs(rt,-1);
    pair<int,int> mx2(-1,0);
    for(int j=1;j<=m;j++)mx2=max(mx2,pair<int,int>(d[j],j));
    rt=mx2.second;
    d[rt]=0;
    dfs(rt,-1);
    for(int j=1;j<=m;j++)dia[i]=max(dia[i],d[j]);
  }
  int sum=0;
  for(auto x:dep)sum+=x;
  int mn=1e9,mx=-1e9;
  for(int i=0;i<n;i++){
    int val=(sum-dep[i])*2+dia[i];
    mn=min(mn,val);
    mx=max(mx,val);
  }
  cout << mx << " " << mn << "\n";
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--)solve();
}