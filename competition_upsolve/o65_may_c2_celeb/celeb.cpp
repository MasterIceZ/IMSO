#include "celeb.h"
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct line_t {
  ll m, c;
  inline ll query(ll x) {
    return m * x + c;
  }
  line_t(ll _m, ll _c):
    m(_m), c(_c) {}
};

struct convex_hull_trick {
  deque<line_t> dq;
  // check l2 is good
  inline bool is_good(line_t l1, line_t l2, line_t l3) {
    return (__int128_t)(l2.c - l1.c) * (l1.m - l3.m) < (__int128_t)(l3.c - l1.c) * (l1.m - l2.m);
  }
  inline void add_line(ll m, ll c) {
    line_t this_line(m, c);
    while ((int)dq.size() > 1 && !is_good(dq[(int)dq.size() - 2], dq[(int)dq.size() - 1], this_line)) {
      dq.pop_back();
    }
    dq.emplace_back(this_line);
  }
  inline ll query(ll x) {
    while ((int)dq.size() > 1 && dq[(int)dq.size() - 1].query(x) <= dq[(int) dq.size() - 2].query(x)) {
      dq.pop_back();
    }
    return dq.back().query(x);
  }
};

convex_hull_trick cht;

vector<ll> max_revenue(int N, int K, vector<ll> X, vector<int> M) {
  for(int i=0; i<N; ++i) {
    cht.add_line((ll) i, X[i]);
  }
  vector<ll> res;
  for(int i=0; i<K; ++i) {
    res.emplace_back(cht.query(-M[i]));
  }
  return res;
}