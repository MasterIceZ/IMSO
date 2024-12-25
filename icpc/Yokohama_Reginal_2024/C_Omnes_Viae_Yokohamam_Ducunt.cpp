#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 100010;
const ll INF = 1e18 + 100ll;

struct state_t {
  int v;
  ll w;
  state_t(int _v, ll _w):
    v(_v), w(_w) {}
  bool operator < (const state_t& o) const {
    return w > o.w;
  }
};

ll w, a[MxN], dist[MxN];
vector<pair<int, ll>> adj[MxN];
priority_queue<state_t> pq;

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for(int i=1; i<=n; ++i) {
    cin >> a[i];
  }
  for(int i=1, u, v; i<=m; ++i) {
    cin >> u >> v >> w;
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
  }
  for(int i=1; i<=n; ++i) {
    dist[i] = INF;
  }
  pq.emplace(1, dist[1] = 0);
  while(!pq.empty()) {
    state_t now = pq.top();
    pq.pop();
    if(now.w != dist[now.v]) {
      continue;
    }
    for(auto [v, w]: adj[now.v]) {
      ll next_dist = now.w + w;
      if(dist[v] > next_dist) {
        pq.emplace(v, dist[v] = next_dist);
      }
    }
  }
  ll answer = 0ll;
  for(int i=1; i<=n; ++i) {
    answer += dist[i] * a[i];
  }
  cout << answer << "\n";
  return 0;
}