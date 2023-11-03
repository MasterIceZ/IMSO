#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 50050;
const int MxS = 55;

struct state_t {
  int v;
  ll w;
  bool operator < (const state_t& o) const {
    return w > o.w;
  }
  state_t(int _v, ll _w):
    v(_v), w(_w) {}
};

vector<pair<int, ll>> adj[MxN];
ll w, dist[MxS][MxN];
set<int> pts;
priority_queue<state_t>pq;
mt19937 rng(time(0));

inline void dijkstra(int state, int stp) {
  // cerr << "current state: " << state << "\n";
  pq.emplace(stp, dist[state][stp] = 0ll);
  while(!pq.empty()) {
    state_t now = pq.top();
    // cerr << "now: " << now.v << "\n";
    pq.pop();
    for(auto x: adj[now.v]) {
      ll nxt = now.w + x.second;
      if(dist[state][x.first] > nxt) {
        pq.emplace(x.first, dist[state][x.first] = nxt);
      }
    }
  }
}

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n, m, s, t, q;
  cin >> n >> s >> t >> m >> q;
  for (int i = 1, u, v; i <= m; ++i) {
    cin >> u >> v >> w;
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
  }
  for (int i = 1, x; i <= s + t; ++i) {
    cin >> x;
    pts.emplace(x);
  }
  memset(dist, 0x3f, sizeof dist);
  for (int st = 1; st < MxS; ++st) {
    int tt;
    do {
      tt = rng() % n + 1;
    } while (pts.count(tt));
    pts.emplace(tt);
    dijkstra(st, tt);
  }
  // cerr << "========ENDED========\n";
  while (q--)
  {
    int a, b;
    cin >> a >> b;
    ll res = 1e18 + 100;
    for (int st = 1; st < MxS; ++st) {
      res = min(res, dist[st][a] + dist[st][b]);
    }
    cout << res << "\n";
  }
  return 0;
}