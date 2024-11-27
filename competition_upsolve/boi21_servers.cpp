#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = ;

vector<pair<int, int>> adj[MxN];

namespace centroid {
  bool used[MxN];
  int sz[MxN];

  int get_sz(int u, int p) {
    sz[u] = 1;
    for(auto [v, w]: adj[u]) {
      if(v == p || used[v]) {
        continue;
      }
      sz[u] += get_sz(v, u);
    }
    return sz[u];
  }

  int find_centroid(int u, int p, int tot) {
    for(auto [v, w]: adj[u]) {
      if(v == p || used[v]) {
        continue;
      }
      if(sz[v] * 2 > tot) {
        return find_centroid(v, u, tot);
      }
    }
    return u;
  }
  
  void decompose(int u) {
    u = find_centroid(u, 0, get_sz(u, 0));
    used[u] = true;
    for(auto [v, w]: adj[u]) {
      if(used[v]) {
        continue;
      }
      decompose(v);
    }
  }
}

namespace heavy_light {
  void dfs_build() {

  }
  void dfs_hld(int u) {

  }
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);

  return 0;
}