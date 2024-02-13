#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<int>> a(3, vector<int> (n + 1)), dp(3, vector<int> (n + 1));
  for(int i=1; i<=n; ++i) {
    for(int state=0; state<=2; ++state) {
      cin >> a[state][i];
    }
  }
  for(int i=1; i<=n; ++i) {
    for(int x=0; x<3; ++x) {
      for(int y=x+1; y<3; ++y) {
        int z = 3 - (x + y);
        dp[z][i] = max(dp[x][i - 1], dp[y][i - 1]) + a[z][i];
      }
    }
  }
  cout << max({dp[0][n], dp[1][n], dp[2][n]}) << "\n";
  return 0;
}