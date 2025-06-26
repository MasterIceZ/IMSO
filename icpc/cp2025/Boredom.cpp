#include <algorithm>
#include <iostream>

const int MxN = 100010;

long long cnt[MxN], dp[MxN];

signed main(int argc, char *argv[]) {
  std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
  int n;
  std::cin >> n;
  for(int i=1, x; i<=n; ++i) {
    std::cin >> x;
    cnt[x] += 1;
  }
  dp[1] = cnt[1];
  for(long long i=2ll; i<MxN; ++i) {
    dp[i] = std::max(dp[i - 2] + (i * cnt[i]), dp[i - 1]);
  }
  std::cout << dp[MxN - 1] << "\n";
  return 0;
}