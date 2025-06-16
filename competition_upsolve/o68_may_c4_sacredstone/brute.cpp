#include "sacredstone.h"

#include <algorithm>
#include <vector>

const long long INF = 1e18 + 100ll;
const int MxN = 100010;

long long a[MxN], c[MxN];

long long sacredstone(int N, std::vector<int> A, std::vector<int> C) {
  for(int i=1; i<=N; ++i) {
    a[i] = (long long) A[i - 1];
    c[i] = (long long) C[N - i];
  }

  std::vector<std::vector<long long>> dp(N, std::vector<long long>(3, -INF));

  dp[1][0] = 0ll;
  for(int state=1; state<=N; ++state) {
    std::vector<std::vector<long long>> new_dp(N, std::vector<long long>(3, -INF));
    for(int i=1; i<=N / 2 + 1; ++i) {
      new_dp[i][0] = std::max({
        dp[i][0],
        dp[i - 1][1] - a[state],
        dp[i - 1][2] + a[state]
      });
      new_dp[i][1] = std::max(
        dp[i][1],
        dp[i][0] + a[state]
      );
      new_dp[i][2] = std::max(
        dp[i][2],
        dp[i][0] - a[state]
      );
    }
    dp = new_dp;
  }

  long long answer = C[N - 1];
  for(int i=1; i<=N; ++i) {
    answer = std::max(answer, dp[i / 2 + 1][i & 1] + c[i]);
  }

  return answer;
}