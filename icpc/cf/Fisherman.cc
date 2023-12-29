#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 1010;

ll a[MxN];
int match[MxN * MxN];
vector<ll> v, adj[MxN * MxN];
bitset<MxN * MxN> visited;

bool kuhn(int u) {
  if(visited[u]) {
    return false;
  }
  visited[u] = true;
  for(auto x: adj[u]) {
    if(match[x] == -1 || kuhn(match[x])) {
      match[x] = u;
      return true;
    }
  }
  return false;
}

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for(int i=1; i<=n; ++i) {
    cin >> a[i];
    for(ll j=1; j<=n; ++j) {
      v.emplace_back(a[i] * j);
    }
  }
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
  for(int i=1; i<=n; ++i) {
    for(ll j=1; j<=n; ++j) {
      int idx = lower_bound(v.begin(), v.end(), a[i] * j) - v.begin();
      adj[idx].emplace_back(i);
    }
  }
  memset(match, -1, sizeof match);
  ll answer = 0ll;
  for(int i=0; i<v.size(); ++i) {
    if(!kuhn(i)) {
      continue;
    }
    answer += v[i];
    visited = 0;
  }
  cout << answer << "\n";
  return 0;
}