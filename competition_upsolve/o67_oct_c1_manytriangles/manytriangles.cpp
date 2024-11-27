#include "manytriangles.h"
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
const int MxN = 24;
 
pair<ll, ll> pts[MxN];
ll dp[1 << MxN]; // answer for mask
 
inline ll get_area(int pt_a, int pt_b, int pt_c) {
  return abs(
    pts[pt_a].first * pts[pt_b].second - pts[pt_b].first * pts[pt_a].second +
    pts[pt_b].first * pts[pt_c].second - pts[pt_c].first * pts[pt_b].second +
    pts[pt_c].first * pts[pt_a].second - pts[pt_a].first * pts[pt_c].second
  );
}
 
ll mincost_color(int C, vector<int> xs, vector<int> ys) {
  int n = C * 3;
  for(int i=0; i<n; ++i) {
    pts[i] = make_pair((ll) xs[i], (ll) ys[i]);
  }
  int max_mask = (1 << n) - 1;
  for(int i=1; i<=max_mask; ++i) {
    dp[i] = 1e18 + 100ll;
  }
  dp[0] = 0;
  for(int cur_mask=1; cur_mask<=max_mask; ++cur_mask) {
    if(__builtin_popcount(cur_mask) % 3 != 0) {
      continue;
    }
    int lsb = (cur_mask & -cur_mask);
    int i = __builtin_ctz(lsb);
    for(int j=i+1; j<n; ++j) {
      if((cur_mask & (1 << j)) == 0) {
        continue;
      }
      for(int k=j+1; k<n; ++k) {
        if((cur_mask & (1 << k)) == 0) {
          continue;
        }
        int from_mask = (cur_mask ^ (1 << i) ^ (1 << j) ^ (1 << k));
        ll new_cost = dp[from_mask] + get_area(i, j, k);
        dp[cur_mask] = min(dp[cur_mask], new_cost);
      }
    }
  }
  return dp[max_mask];
}