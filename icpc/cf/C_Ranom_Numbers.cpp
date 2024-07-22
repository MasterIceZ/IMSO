#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 200020; 

int dp[2][6][MxN];

inline int power_10(int p) {
  if(p > 5 || p < 1) {
    return 0;
  }
  int res = 1;
  while(--p) {
    res *= 10;
  }
  return res;
}

inline void solve() {
  string s;
  cin >> s;
  int n = (int) s.size();
  s = " " + s;
  for(int j=0; j<=5; ++j) {
      for(int i=1; i<=n+1; ++i) {
        dp[0][j][i] = dp[1][j][i] = -1e9 - 100;
      }
  }
  dp[0][1][n + 1] = 0;
  for(int i=n; i>=1; --i) {
    for(int j=1; j<=5; ++j) {
      for(int state=0; state<=1; ++state) {
        int chr = max(s[i] - 'A' + 1, j);
        int to_add = (s[i] - 'A' + 1 >= j ? 1: -1) * power_10(s[i] - 'A' + 1);
        dp[state][chr][i] = max(dp[state][chr][i], dp[state][j][i + 1] + to_add);
      }
    }
    for(int j=1; j<=5; ++j) {
      for(int k=1; k<=5; ++k) {
        int chr = max(j, k);
        int to_add = (j >= k ? 1: -1) * power_10(j);
        dp[1][chr][i] = max(dp[1][chr][i], dp[0][k][i + 1] + to_add);
      }
    }
  }
  int answer = -1e9 - 100;
  for(int chr=1; chr<=5; ++chr) {
    answer = max({answer, dp[0][chr][1], dp[1][chr][1]});
  }
  cout << answer << "\n";
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