#include <bits/stdc++.h>

using namespace std;

const int MxN = 22;

double a[MxN][MxN], dp[1 << 20];

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for(int i=0; i<n; ++i) {
    for(int j=0; j<n; ++j) {
      cin >> a[i][j];
      a[i][j] /= 100;
    }
  }
  dp[0] = 1.0;
  for(int i=0; i<(1 << n); ++i) {
    for(int j=0; j<n; ++j) {
      if((i >> j) & 1 == 0) {
        continue;
      }
      int cnt_zero = __builtin_popcount(i);
      dp[i] = max(dp[i], dp[i ^ (1 << j)] * a[cnt_zero - 1][j]);
    }
  }
  cout << fixed << setprecision(12) << 100 * dp[(1 << n) - 1] << "\n";
}