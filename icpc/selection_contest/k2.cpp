#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
  int n;
  cin >> n;
  vector<ll> dia(n),dep(n,-1);
  for(int i=0;i<n;i++){
    int m;
    cin >> m;
    vector<vector<int>> adj(m+2);
    int rt=0;
    for(int j=1;j<=m;j++){
      int p;
      cin >> p;
      if(p==0){
        rt=j;
      }else{
        adj[p].emplace_back(j);
        adj[j].emplace_back(p);
      }
    }
    vector<ll> d(m+2);
    function<void(int,int)> dfs=[&](int u,int p){
      for(auto v:adj[u])if(v!=p){
        d[v]=d[u]+1;
        dfs(v,u);
      }
    };
    d[rt]=0;
    dfs(rt,0);
    for(int j=1;j<=m;j++){
      if(d[j]>dep[i]){
        dep[i]=d[j];
        rt=j;
      }
      d[j]=0;
    }
    dfs(rt,0);
    for(int j=1;j<=m;j++)dia[i]=max(dia[i],d[j]);
  }
  ll sum=0,mn=1e18,mx=-1e18;
  for(int i=0;i<n;i++)sum+=dep[i];
  for(int i=0;i<n;i++){
    ll res=dia[i]+(sum-dep[i])*2;
    mn=min(mn,res);
    mx=max(mx,res);
  }
  cout << mx << " " << mn << "\n";
}

int main(){
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--)solve();
}