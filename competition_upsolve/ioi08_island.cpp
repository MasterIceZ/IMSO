#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 1000010;

pair<int, ll> nxt[MxN];
bitset<MxN> cycle;
int in[MxN];
queue<int> q;
ll dist[MxN], dp[MxN];

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for(int i=1; i<=n; ++i) {
    cin >> nxt[i].first >> nxt[i].second;
    in[nxt[i].first]++;
  }
  for(int i=1; i<=n; ++i) {
    if(in[i] != 0) {
      continue;
    }
    q.emplace(i);
  }
  while(!q.empty()) {
    int u = q.front(); q.pop();
    int v = nxt[u].first;
    ll w = nxt[u].second;
    dp[v] = max({dp[u], dp[v], dist[v] + dist[u] + w});
    dist[v] = max(dist[v], dist[u] + w);
    if (--in[v] == 0) {
        q.emplace(v);
    }
  }
#ifdef ICY
  for(int i=1; i<=n; ++i) {
    cerr << "D: " << dp[i] << " " << dist[i] << "\n";
  }
#endif
  auto calc = [&](int pos) {
    int cur_pos = pos;
    cur_pos = nxt[pos].first;
    ll cur_dist = nxt[pos].second;
    ll with = dist[pos];
    ll without = dist[pos];
    ll max_dp_with = dp[pos];
    ll max_dp_without = -1e18 - 100ll;
#ifdef ICY
    cerr << "PRE: " << max_dp_with << " " << max_dp_without << " " << cur_dist << "\n";
#endif
    while(cur_pos != pos) {
      in[cur_pos] = 0;
      max_dp_with = max({max_dp_with, dp[cur_pos], dist[cur_pos] + cur_dist + with});
      max_dp_without = max(max_dp_without, dist[cur_pos] - cur_dist + without);
      with = max(with, dist[cur_pos] - cur_dist);
      without = max(without, dist[cur_pos] + cur_dist);
      cur_dist += nxt[cur_pos].second;
      cur_pos = nxt[cur_pos].first;
#ifdef ICY
      cerr << "A: " << max_dp_with << " " << max_dp_without << "\n";
#endif
   }
    return max(max_dp_without + cur_dist, max_dp_with);
  };
  ll answer = 0ll;
  for(int i=1; i<=n; ++i) {
    if(in[i] == 0) {
      continue;
    }
#ifdef ICY
    cerr << "X: " << i << "\n";
#endif
    answer += calc(i);
  }
  cout << answer << "\n";
  return 0;
}