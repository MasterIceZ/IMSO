#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 110;

int n, k, dp[MxN][MxN][MxN], p[4];
char a[4][MxN];

int DP(int i, int j, int k) {
  if(i < 0 || j < 0 || k < 0) {
    return -1e9 - 100;
  }
  if(i == 0 && j == 0 && k == 0) {
    return 0;
  }
  if(dp[i][j][k] != -1) {
    return dp[i][j][k];
  }
  dp[i][j][k] = max({DP(i - 1, j, k), DP(i, j - 1, k), DP(i, j, k - 1)});
  if(i > 0 && a[1][i] == '.') {
    int x = min(i, max(0, i - p[0]));
    int y = min(j, max(0, i - p[1]));
    int z = min(k, max(0, i - p[2]));
    dp[i][j][k] = max(dp[i][j][k], 1 + DP(x, y, z));
  }
  if(j > 0 && a[2][j] == '.') {
    int x = min(i, max(0, j - p[1]));
    int y = min(j, max(0, j - p[0]));
    int z = min(k, max(0, j - p[1]));
    dp[i][j][k] = max(dp[i][j][k], 1 + DP(x, y, z));
  }
  if(k > 0 && a[3][k] == '.') {
    int x = min(i, max(0, k - p[2]));
    int y = min(j, max(0, k - p[1]));
    int z = min(k, max(0, k - p[0]));
    dp[i][j][k] = max(dp[i][j][k], 1 + DP(x, y, z));
  }
  return dp[i][j][k];
}

bool ok(int mid) {
  for(int i=0; i<=n; ++i) {
    for(int j=0; j<=n; ++j) {
      for(int k=0; k<=n; ++k) {
        dp[i][j][k] = -1;
      }
    }
  }
  for(int i=0; i<3; ++i) {
    int l = 0, r = n;
    while(l < r) {
      int md = (l + r) >> 1;
      if(md * md >= mid - i * i) {
        r = md;
      }
      else {
        l = md + 1;
      }
    }
    p[i] = l;
  }
  return DP(n, n, n) >= k;
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  cin >> n >> k;
  int remains = k;
  for(int i=1; i<=3; ++i) {
    for(int j=1; j<=n; ++j) {
      cin >> a[i][j];
      remains -= (a[i][j] == '.');
    }
  }
  if(remains > 0) {
    cout << -1 << "\n";
    return 0;
  }
  int l = 1, r = 20020;
  while(l < r) {
    int mid = (l + r + 1) >> 1;
    if(ok(mid)) {
      l = mid;
    }
    else {
      r = mid - 1;
    }
  }
  cout << fixed << setprecision(7) << sqrt(l) << "\n";
  return 0;
}