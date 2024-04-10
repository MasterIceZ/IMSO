#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 200020;

struct node_t;
using pnode_t = node_t*;

struct node_t {
  ll val;
  pnode_t l, r;
  node_t(ll _val):
    val(_val), l(nullptr), r(nullptr) {}
};

ll a[MxN];
pnode_t roots[MxN];

void build(int l, int r, pnode_t &cur) {
  cur = new node_t(0ll);
  if(l == r) {
    cur->val = a[l];
    return ;
  }
  int mid = (l + r) >> 1;
  build(l, mid, cur->l);
  build(mid + 1, r, cur->r);
  cur->val = cur->l->val + cur->r->val;
}

void update(int l, int r, int id, ll v, pnode_t &cur, pnode_t pre) {
  cur = new node_t(*pre);
  if(l == r) {
    cur->val = v;
    return ;
  }
  int mid = (l + r) >> 1;
  if(l <= mid) {
    update(l, mid, id, v, cur->l, pre->l);
  }
  else {
    update(mid + 1, r, id, v, cur->r, pre->r);
  }
  cur->val = cur->l->val + cur->r->val;
}

ll query(int l, int r, int wl, int wr, pnode_t cur) {
  if(l > r || l > wr || r < wl) {
    return 0ll;
  }
  if(wl <= l && r <= wr) {
    return cur->val;
  }
  int mid = (l + r) >> 1;
  return query(l, mid, wl, wr, cur->l) + query(mid + 1, r, wl, wr, cur->r);
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  for(int i=1; i<=n; ++i) {
    cin >> a[i];
  }
  return 0;
}