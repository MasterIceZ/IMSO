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
  sort(pts, pts + n, [&](pair<ll, ll> a, pair<ll, ll> b) {
    if(a.second != b.second) {
      return a.second < b.second;
    }
    return a.first < b.first;
  });
  ll res = 0ll;
  for(int i=0; i<n; i+=3) {
    res += get_area(i, i + 1, i + 2);
  }
  return res;
}