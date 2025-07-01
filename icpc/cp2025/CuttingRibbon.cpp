#include <algorithm>
#include <cstring>
#include <iostream>

const int MxN = 4040;

int dp[MxN];

signed main(int argc, char *argv[]) {
  std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
  int n, a, b, c;
  std::cin >> n >> a >> b >> c;
  memset(dp, -0x3f, sizeof dp);
  dp[0] = 0;
  for(int i=1; i<=n; ++i) {
    if(i >= a) {
      dp[i] = std::max(dp[i], dp[i - a] + 1);
    }
    if(i >= b) {
      dp[i] = std::max(dp[i], dp[i - b] + 1);
    }
    if(i >= c) {
      dp[i] = std::max(dp[i], dp[i - c] + 1);
    }
  }
  std::cout << dp[n] << "\n";
  return 0;
}