#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 110;
const int MxV = MxN * 1000;

int dp[MxV], wei[MxN], val[MxN];

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n, w;
  cin >> n >> w;
  for(int i=1; i<=n; ++i) {
    cin >> wei[i] >> val[i];
  }
  int sum_v = accumulate(val + 1, val + n + 1, 0);
  memset(dp, 0x3f, sizeof dp);
  dp[0] = 0;
  for(int i=1; i<=n; ++i) {
    for(int j=sum_v; j>=val[i]; --j) {
      dp[j] = min(dp[j], dp[j - val[i]] + wei[i]);
    }
  }
  for(int i=sum_v; i>=1; --i) {
    if(dp[i] > w) {
      continue;
    }
    cout << i << "\n";
    exit(0);
  }
  return 0;
}