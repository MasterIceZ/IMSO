#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 500050;
const int MxK = 22;
const int ZERO = 20;
const int INF = 1e9 + 100;

int k, dp[2 * MxK][MxN];
string s, t;

int DP(int n, int m) {
  int diff = m - n;
  if(abs(diff) > k) {
    return INF;
  }
  if(n == 0 || m == 0) {
    return max(n, m);
  }
  if(dp[diff + ZERO][m] != -1) {
    return dp[diff + ZERO][m];
  }
  dp[diff + ZERO][m] = min({
    DP(n - 1, m - 1) + (s[n] != t[m]),
    DP(n - 1, m) + 1,
    DP(n, m - 1) + 1 
  });
  return dp[diff + ZERO][m];
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  cin >> k >> s >> t;
  int n = s.size(), m = t.size();
  s = " " + s; t = " " + t;
  memset(dp, -1, sizeof dp);
  cout << (DP(n, m) <= k ? "Yes": "No") << "\n";
  return 0;
}