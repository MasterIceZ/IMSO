#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct HopcroftKarp{
    int n,m;
    vector<int> l,r,lv,ptr;
    vector<vector<int>> adj;
    HopcroftKarp(){}
    HopcroftKarp(int _n,int _m){init(_n,_m);}
    void init(int _n,int _m){
        n=_n,m=_m;
        adj.assign(n+m,{});
    }
    void addEdge(int u,int v){
        adj[u].emplace_back(v+n);
    }
    void bfs(){
        lv.assign(n,-1);
        queue<int> q;
        for(int i=0;i<n;i++)if(l[i]==-1){
            lv[i]=0;
            q.emplace(i);
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int v:adj[u])if(r[v]!=-1&&lv[r[v]]==-1){
                lv[r[v]]=lv[u]+1;
                q.emplace(r[v]);
            }
        }
    }
    bool dfs(int u){
        for(int &i=ptr[u];i<adj[u].size();i++){
            int v=adj[u][i];
            if(r[v]==-1||(lv[r[v]]==lv[u]+1&&dfs(r[v]))){
                l[u]=v,r[v]=u;
                return true;
            }
        }
        return false;
    }
    int maxMatching(){
        int match=0,cnt=0;
        l=r=vector<int>(n+m,-1);
        do{
            ptr.assign(n,0);
            bfs();
            cnt=0;
            for(int i=0;i<n;i++)if(l[i]==-1&&dfs(i))cnt++;
            match+=cnt;
        }while(cnt);
        return match;
    }
};

const int MxN = 110;

int a[MxN][MxN], cnt[2][MxN][MxN];

inline void solve() {
  int n;
  cin >> n;
  for(int i=0; i<n; ++i) {
    for(int j=0; j<n; ++j) {
      cin >> a[i][j];
      cnt[0][a[i][j]][i]++;
      cnt[1][a[i][j]][j]++;
    }
  }
  HopcroftKarp mbm(n, n);
  for(int i=0; i<n; ++i) {
    for(int j=0; j<n; ++j) {
      for(int x=1; x<=n; ++x) {
        if(cnt[0][x][i] <=1 || cnt[1][x][j] <= 1) {
          continue;
        }
        mbm.addEdge(i, j);
        break;
      }
    }
  }
  int mt = mbm.maxMatching();
  cout << n - mt << "\n";
  int ptr_l = 0, ptr_r = n;
  for(int i=1; i<=n - mt; ++i) {
    while(mbm.l[ptr_l] != -1) {
      ptr_l++;
    }
    while(mbm.r[ptr_r] != -1) {
      ptr_r++;
    }
    cout << ptr_l + 1 << " " << ptr_r - n + 1 << " ";
    int pl = ptr_l, pr = ptr_r - n;
    for(int x=1; x<=n; ++x) {
      if(x == a[pl][pr]) {
        continue;
      }
      if(cnt[0][x][pl] >= 1 && cnt[1][x][pr] >= 1) {
        cout << x << "\n";
        break;
      }
    }
    ptr_l++, ptr_r++;
  }
  memset(cnt, 0, sizeof cnt);
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}