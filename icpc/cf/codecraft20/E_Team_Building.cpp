#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxP = 7;
const int MxN = 100010;

struct player_t {
  ll power;
  ll add_power[MxP];
  bool operator < (const player_t &o) const {
    return power > o.power;
  }
};

player_t a[MxN];

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n, p, k;
  cin >> n >> p >> k;
  for(int i=1; i<=n; ++i) {
    cin >> a[i].power;
  }
  for(int i=1; i<=n; ++i) {
    for(int j=0; j<p; ++j) {
      cin >> a[i].add_power[j];
    }
  }
  sort(a + 1, a + n + 1);
  int max_mask = (1 << p) - 1;
  vector<ll> dp(max_mask + 1, -1e18 - 100ll);
  dp[0] = 0;
  for(int i=1; i<=n; ++i) {
    vector<ll> new_dp = dp;
    for(int mask=0; mask<=max_mask; ++mask) {
      for(int adding=0; adding<p; ++adding) {
        int cur_add = (1 << adding);
        int new_mask = (mask | cur_add);
        if(cur_add & mask) {
          int remove_mask = (mask ^ cur_add);
          new_dp[new_mask] = max(new_dp[new_mask], dp[remove_mask] + a[i].add_power[adding]);
        }
        else {
          new_dp[new_mask] = max(new_dp[new_mask], dp[mask] + a[i].add_power[adding]);
        }
        int bit_count = __builtin_popcount(mask);
        if (i < bit_count + 1 + k) {
          new_dp[mask] = max(new_dp[mask], dp[mask] + a[i].power);
        }
      }
    }
    dp = new_dp;
  }
  cout << dp[max_mask] << "\n";
  return 0;
}