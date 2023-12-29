#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 22;

int a[MxN];
ll dp[MxN][1 << 20];

inline int count_three_bit(int x) {
  int res = 0;
  while(x > 0) {
    res += (x % 3 == 1);
    x /= 3;
  }
  return res;
}

inline bool ok(int a, int b) {
  return __builtin_popcount(a) == __builtin_popcount(b) || count_three_bit(a) == count_three_bit(b);
}

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for(int i=0; i<n; ++i) {
    cin >> a[i];
    dp[i][1 << i] = 1ll;
  }
  int max_mask = (1 << n) - 1;
  for(int cur_mask=1; cur_mask<=max_mask; ++cur_mask) {
    for(int i=0; i<n; ++i) {
      if(!(cur_mask & (1 << i))) {
        continue;
      }
      for(int j=0; j<n; ++j) {
        if(cur_mask & (1 << j) || !ok(a[i], a[j])) {
          continue;
        }
        int next_mask = cur_mask | (1 << j);
        dp[j][next_mask] += dp[i][cur_mask];
      }
    }
  }
  ll res = 0ll;
  for(int i=0; i<n; ++i) {
    res += dp[i][max_mask];
  }
  cout << res << "\n";
  return 0;
}