#include <algorithm>
#include <iostream>

const int MxN = 18;

long long a[MxN], rules[MxN][MxN], dp[MxN][1 << MxN];

signed main(int argc, char *argv[]) {
  std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
  int n, m, k;
  std::cin >> n >> m >> k;
  for(int i=0; i<n; ++i) {
    std::cin >> a[i];
  }
  for(int i=0, x, y; i<k; ++i) {
    long long c;
    std::cin >> x >> y >> c;
    rules[--x][--y] = c;
  }
  long long answer = *std::max_element(a, a + n);
  for(int i=0; i<n; ++i) {
    dp[i][1 << i] = a[i];
  }
  int max_mask = (1 << n) - 1;
  for(int mask=1; mask<=max_mask; ++mask) {
    if(__builtin_popcount(mask) > m) {
      continue;
    }
    for(int i=0; i<n; ++i) {
      if(!(mask & (1 << i))) {
        continue;
      }
      int without_i = mask ^ (1 << i);
      for(int j=0; j<n; ++j) {
        if(i == j || !(without_i & (1 << j))) {
          continue;
        }
        dp[i][mask] = std::max(dp[i][mask], dp[j][without_i] + a[i] + rules[j][i]);
        answer = std::max(answer, dp[i][mask]);
      }
    }
  }
  std::cout << answer << "\n";
  return 0;
}