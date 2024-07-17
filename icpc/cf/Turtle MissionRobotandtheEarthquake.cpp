#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 1010;

int a[MxN][MxN], dist[MxN][MxN];
queue<pair<int, int>> q;
bitset<MxN> visited[MxN];

inline void solve() {
  int n, m;
  cin >> n >> m;
  for(int i=0; i<=n-1; ++i) {
    for(int j=0; j<=m-1; ++j) {
      cin >> a[i][j];
    }
  }
  for(int i=0; i<=n-1; ++i) {
    for(int j=0; j<=m-1; ++j) {
      dist[i][j] = -1;
    }
  }
  q.emplace(0, 0);
  dist[0][0] = 0;
  while(!q.empty()) {
    auto [cur_i, cur_j]= q.front(); q.pop();
    if(a[(2 * cur_i + cur_j)][cur_j] == 0 )
  }
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