#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 550;

string a[2][MxN];
int row[2][MxN], col[2][MxN];

inline void solve() {
  int n, m;
  cin >> n >> m;
  for(int i=1; i<=n; ++i) {
    cin >> a[0][i];
    a[0][i] = " " + a[0][i];
  }
  for(int i=1; i<=n; ++i) {
    cin >> a[1][i];
    a[1][i] = " " + a[1][i];
  }
  for(int i=1; i<=n; ++i) {
    row[0][i] = row[1][i] = 0;
  }
  for(int j=1; j<=m; ++j) {
    col[0][j] = col[1][j] = 0;
  }
  for(int i=1; i<=n; ++i) {
    for(int j=1; j<=m; ++j) {
      for(int state=0; state<=1; ++state) {
        row[state][i] = (row[state][i] + (a[state][i][j] - '0')) % 3;
        col[state][j] = (col[state][j] + (a[state][i][j] - '0')) % 3;
      }
    }
  }
  bool ok = true;
  for(int i=1; i<=n; ++i) {
    ok &= (row[0][i] == row[1][i]);
  }
  for(int j=1; j<=m; ++j) {
    ok &= (col[0][j] == col[1][j]);
  }
  cout << (ok ? "YES": "NO") << "\n";
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