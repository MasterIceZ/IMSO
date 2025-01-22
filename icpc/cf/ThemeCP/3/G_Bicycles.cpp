#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 1010;
const ll INF = 1e18 + 100ll;

struct state_t {
  int v;
  ll w, s;
  state_t(int _v, ll _w, ll _s):
    v(_v), w(_w), s(_s) {}
  bool operator < (const state_t &o) const {
    return w > o.w;
  }
};

vector<pair<int, ll>> adj[MxN];
priority_queue<state_t> pq;
ll dist[MxN][MxN], w, speed[MxN];

inline void solve() {
  int n, m;
  cin >> n >> m;
  for(int i=1, u, v; i<=m; ++i) {
    cin >> u >> v >> w;
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
  }
  for(int i=1; i<=n; ++i) {
    cin >> speed[i];
  }
  int max_speed = *max_element(speed + 1, speed + n + 1);
  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=max_speed; ++j) {
      dist[i][j] = INF;
    }
  }
  pq.emplace(1, dist[1][speed[1]] = 0ll, speed[1]);
  while(!pq.empty()) {
    state_t now = pq.top();
    pq.pop();
    if(now.v == n) {
      cout << now.w << "\n";
      break;
    }
    for(auto [v, w]: adj[now.v]) {
      ll nxt_dist = now.w + w * now.s;
      if(speed[v] < now.s && dist[v][speed[v]] > nxt_dist) {
        pq.emplace(v, dist[v][speed[v]] = nxt_dist, speed[v]);
      }
      if(dist[v][now.s] > nxt_dist) {
        pq.emplace(v, dist[v][now.s] = nxt_dist, now.s);
      }
    }
  }
  for(int i=1; i<=n; ++i) {
    adj[i].clear();
  }
  while(!pq.empty()) {
    pq.pop();
  }
  return ;
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