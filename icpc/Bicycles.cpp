#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 1010;

struct state_t {
  int v;
  ll w;
  int slowness;
  bool operator < (const state_t &o) const {
    return w > o.w;
  }
  state_t(int _v, ll _w, int _slowness):
    v(_v), w(_w), slowness(_slowness) {}
};

int n, m, u, v, w, dist[MxN][MxN], s[MxN];
vector<pair<int, ll>> adj[MxN];
priority_queue<state_t> pq;

inline void solve() {
  cin >> n >> m;
  for(int i=1; i<=m; ++i) {
    cin >> u >> v >> w;
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
  }
  memset(dist, 0x3f, sizeof dist);
  pq.emplace(1, dist[1][s[1]] = 0, s[1]);
  while(!pq.empty()) {
    state_t now = pq.top(); pq.pop();
    for(auto x: adj[now.v]) {
      int nxt_slowness = min(now.slowness, s[x.first]);
      int nxt = now.w + x.second * now.slowness;
      if(dist[x.first][nxt_slowness] > nxt) {
        pq.emplace(x.first, dist[x.first][nxt_slowness] = nxt, nxt_slowness);
      }
    }
  }
  cout << *min_element(dist[n], dist[n] + 1000);
}

int main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);

  int t;
  cin >> t;
  while(t--) {
    solve();
    cout << "\n";
  }

  return 0;
}