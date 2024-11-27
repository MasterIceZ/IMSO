#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using row = vector<int>;
using matrix = vector<row>;

int n, m;

inline vector<vector<int>> read_matrix() {
  matrix res(n + 1, row(m + 1));
  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=m; ++j) {
      cin >> res[i][j];
    }
  }
  return res;
}

void solve() {
  cin >> n >> m;
  array<matrix, 2> a = {read_matrix(), read_matrix()};
  int max_num = n * m;
  array<row, 2> ps_i = {row(max_num + 1), row(max_num + 1)};
  array<row, 2> ps_j = {row(max_num + 1), row(max_num + 1)};
  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=m; ++j) {
      ps_i[0][a[0][i][j]] = ps_i[1][a[1][i][j]] = i;
      ps_j[0][a[0][i][j]] = ps_j[1][a[1][i][j]] = j;
    }
  }
  vector<set<int>> s_i(max_num + 1), s_j(max_num + 1);
  for(int i=1; i<=max_num; ++i) {
    s_i[ps_i[0][i]].emplace(ps_i[1][i]);
    s_j[ps_j[0][i]].emplace(ps_j[1][i]);
  }
  for(int i=1; i<=max_num; ++i) {
    if((int) s_i[i].size() <= 1 && (int) s_j[i].size() <= 1) {
      continue;
    }
    cout << "NO\n";
    return ;
  }
  cout << "YES\n";
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