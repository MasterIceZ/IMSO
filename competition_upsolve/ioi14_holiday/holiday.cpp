#include <bits/stdc++.h>
#include"holiday.h"

using namespace std;
using ll = long long;

const int MxN = 100010;

struct node_t;
using pnode_t = node_t *;

struct node_t {
  ll v;
  int cnt;
  pnode_t l, r;
  node_t(ll _v=0ll, int _cnt=0):
    v(_v), cnt(_cnt), l(nullptr), r(nullptr) {}
  friend node_t operator + (const node_t &lhs, const node_t &rhs) {
    return node_t(lhs.v + rhs.v, lhs.cnt + rhs.cnt);
  }
};

struct interval_t {
  ll v;
  int l, r;
  interval_t(ll _v):
    v(_v), l(-1), r(-1) {}
};

int n, stp, days;
ll a[MxN];
pnode_t roots[MxN];

namespace persistent {
  void build(int l, int r, pnode_t &cur) {
    cur = new node_t();
    if(l == r) {
      cur->v = 0ll;
      cur->cnt = 0ll;
      return ;
    }
    int mid = (l + r) >> 1;
    build(l, mid, cur->l);
    build(mid + 1, r, cur->r);
    cur->v = cur->l->v + cur->r->v;
    cur->cnt = cur->l->cnt + cur->r->cnt;
  }
  void update(int l, int r, int id, node_t val, pnode_t &cur, pnode_t pre) {
    cur = new node_t(*pre);
    if(l == r) {
      cur->v = val.v;
      cur->cnt = 1;
      return ;
    }
    int mid = (l + r) >> 1;
    if(id <= mid) {
      update(l, mid, id, val, cur->l, pre->l);
    }
    else {
      update(mid + 1, r, id, val, cur->r, pre->r);
    }
    cur->v = cur->l->v + cur->r->v;
    cur->cnt = cur->l->cnt + cur->r->cnt;
  }
  ll calc(int l, int r, pnode_t old_ver, pnode_t new_ver, ll x) {
    if(l > r) {
      return 0ll;
    }
    if(l == r) {
      if(x <= 0ll) {
        return 0ll;
      }
      // if(new_ver->cnt - old_ver->cnt <= x) {
      return new_ver->v - old_ver->v;
      // }
    }
    int mid = (l + r) >> 1;
    ll right_count = new_ver->r->cnt - old_ver->r->cnt;
    if(right_count >= x) {
      return calc(l, mid, old_ver->l, new_ver->l, x);
    }
    return (new_ver->r->v - old_ver->r->v) + calc(mid + 1, r, old_ver->r, new_ver->r, x - right_count);
  }
}

ll divide(int l, int r, int opt_l, int opt_r) {
  if(l > r) {
    return 0ll;
  }
  int mid = (l + r) >> 1;
  ll res = 0ll;
  interval_t best(0ll);
  cerr << "T: " << opt_l << " " << opt_r << "\n";
  for(int k=opt_l; k<=opt_r; ++k) {
    int needs = mid - k + min(stp - k, mid - stp);
    if(needs > days) {
      continue;
    }
    assert(k <= mid);
    cerr << "X: " << l << " " << r << " " << needs << "\n";
    ll cur_answer = persistent::calc(0, n-1, roots[k], roots[mid + 1], days - needs);
    // cerr << l << " " << r << " " << cur_answer << "\n";
    if(best.v < cur_answer) {
      best.v = cur_answer;
      best.l = best.r = k;
    }
    else if(best.v == cur_answer) {
      best.r = k;
    }
  }
  res = max({best.v, divide(l, mid - 1, opt_l, best.r), divide(mid + 1, r, best.l, opt_r)});
  return res;
}

long long findMaxAttraction(int n, int start, int d, int attraction[]) {
  stp = start;
  days = d;
  ::n = n;
  vector<pair<ll, int>> c_a;
  for(int i=0; i<=n-1; ++i) {
    a[i] = (ll) attraction[i];
    c_a.emplace_back(a[i], i);
  }
  sort(c_a.begin(), c_a.end());
  persistent::build(0, n-1, roots[0]);
  for(int i=0; i<=n-1; ++i) {
    int idx = lower_bound(c_a.begin(), c_a.end(), make_pair(a[i], i)) - c_a.begin();
    persistent::update(0, n-1, idx, node_t(c_a[idx].first, 1), roots[i + 1], roots[i]);
  }
  ll answer = divide(start, n-1, 0, start);
  return answer;
}
