#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const double SQRT2 = sqrt(2);

struct segment_tree {
  struct value_t {
    int val, cnt; // (min, cnt)
    value_t(int _val=0, int _cnt=0):
      val(_val), cnt(_cnt) {}
    friend value_t operator + (value_t lhs, value_t rhs) {
      if(lhs.val < rhs.val) {
        return lhs;
      }
      if(rhs.val < lhs.val) {
        return rhs;
      }
      return value_t(lhs.val, lhs.cnt + rhs.cnt);
    }
  };
  struct node_t;
  using pnode_t = node_t*;
  struct node_t {
    value_t val;
    int lazy;
    pnode_t l, r;
    node_t(value_t _val):
      val(_val), lazy(0), l(nullptr), r(nullptr) {}
  };
  pnode_t rt;
  int n;
  value_t make_value(int l, int r) {
    return value_t(0, r - l + 1);
  }
  segment_tree(int _n):
    n(_n), rt(new node_t(make_value(0, n-1))) {}
  void apply(int l, int r, int v, pnode_t &cur) {
    if(!cur) {
      cur = new node_t(make_value(l, r));
    }
    cur->val.val += v;
    cur->lazy += v;
  }
  void push_lazy(int l, int mid, int r, pnode_t cur) {
    apply(l, mid, cur->lazy, cur->l);
    apply(mid + 1, r, cur->lazy, cur->r);
    cur->lazy = 0;
  }
  void update(int l, int r, int wl, int wr, int v, pnode_t cur) {
    if(l > wr || r < wl) {
      return ;
    }
    if(wl <= l && r <= wr) {
      apply(l, r, v, cur);
      return ;
    }
    int mid = (l + r) >> 1;
    push_lazy(l, mid, r, cur);
    update(l, mid, wl, wr, v, cur->l);
    update(mid + 1, r, wl, wr, v, cur->r);
    cur->val = cur->l->val + cur->r->val;
  }
  void update(int wl, int wr, int v) {
    update(0, n - 1, wl, wr, v, rt);
  }
};

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n, w;
  cin >> n >> w;
  segment_tree seg(w);
  map<pair<int, int>, bool> status;
  for(int i=1, x, y; i<=n; ++i) {
    cin >> x >> y;
    int l = x - y, r = x + y - 1;
    if(status[make_pair(x, y)] == true) {
      seg.update(l, r, -1);
    }
    else {
      seg.update(l, r, 1);
    }
    status[make_pair(x, y)] ^= true;
    double answer = (double) w;
    auto query_val = seg.rt->val;
    if(query_val.val == 0) {
      answer -= query_val.cnt;
    }
    answer *= SQRT2;
    cout << fixed << setprecision(6) << answer << "\n";
  }
  return 0;
}
