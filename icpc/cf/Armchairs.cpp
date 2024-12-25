#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 5050;
const int OFFSET = 5000;
const int INF = 1e9 + 100;

int a[MxN];

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for(int i=1; i<=n; ++i) {
    cin >> a[i];
  }
  vector<int> dp(MxN * 2, INF);
  dp[OFFSET] = 0;
  for(int i=1; i<=n; ++i) {
    vector<int> new_dp(MxN * 2, INF);
    if(a[i] == 1) {
      for(int j=1; j<=OFFSET*2; ++j) {
        int val = abs(j - 1 - OFFSET);
        new_dp[j] = min(new_dp[j], dp[j - 1] + val);
      }
    }
    else {
      for(int j=0; j<=OFFSET*2; ++j) {
        if(j != OFFSET*2) {
          int val = abs(j + 1 - OFFSET);
          new_dp[j] = min(new_dp[j], dp[j + 1] + val);
        }
        int val = abs(j - OFFSET);
        new_dp[j] = min(new_dp[j], dp[j] + val);
      }
    }
    dp = new_dp;
  }
  cout << dp[OFFSET] << "\n";
  return 0;
}