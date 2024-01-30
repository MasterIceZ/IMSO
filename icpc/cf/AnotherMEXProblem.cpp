#include <bits/stdc++.h>

using namespace std;

const int MxN = 5050;
const int MxW = 8192;

int a[MxN], frq[MxN], range_mex[MxN][MxN], dp[MxW];

inline void solve() {
  int n, max_mask;
  cin >> n;
  max_mask = (1 << (__lg(n) + 1)) - 1;
  for(int i=1; i<=n; ++i) {
    cin >> a[i];
  }
  for(int l=1; l<=n; ++l) {
    for(int i=0; i<=n; ++i) {
      frq[i] = 0;
    }
    int mex = 0;
    for(int r=l; r<=n; ++r) {
      frq[a[r]]++;
      while(frq[mex] > 0) {
        mex++;
      }
      range_mex[l][r] = mex;
    }
  }
  dp[0] = 0;
  for(int cur_mask=1; cur_mask<=max_mask; ++cur_mask) {
    dp[cur_mask] = 1e9 + 100;
  }
  for(int r=1; r<=n; ++r) {
    for(int l=1; l<=r; ++l) {
      if(range_mex[l][r] == range_mex[l + 1][r] || range_mex[l][r] == range_mex[l][r - 1]) {
        continue;
      }
      for(int cur_mask=0; cur_mask<=max_mask; ++cur_mask) {
        if(dp[cur_mask] >= l) {
          continue;
        }
        dp[cur_mask ^ range_mex[l][r]] = min(dp[cur_mask ^ range_mex[l][r]], r);
      }
    }
  }
  for(int cur_mask=max_mask; cur_mask>=0; --cur_mask) {
    if(dp[cur_mask] >= 1e9 + 100) {
      continue;
    }
    cout << cur_mask;
    return ;
  }
  return ;
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) {
    solve();
    cout << "\n";
  }
  return 0;
}