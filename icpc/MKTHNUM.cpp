#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 100010;

struct node_t;

using pnode_t = node_t *;

struct node_t {
  int val;
  pnode_t l, r;
  node_t(int _val): 
    val(_val), l(nullptr), r(nullptr) {}
};

int a[MxN];

void build(int l, int r, pnode_t &cur) {
  cur = new node_t(0);
  if(l == r) {
    cur->val = 0;
    return ;
  }
  int mid = (l + r) >> 1;
  build(l, mid, cur->l);
  build(mid + 1, r, cur->r);
  cur->val = cur->l->val + cur->r->val;
}

void update(int l, int r, int id, int v, pnode_t &cur, pnode_t pre) {
  cur = new node_t(*pre);
  if(l == r) {
    cur->val += v;
    return ;
  }
  int mid = (l + r) >> 1;
  if(id <= mid) {
    update(l, mid, id, v, cur->l, pre->l);
  }
  else {
    update(mid + 1, r, id, v, cur->r, pre->r);
  }
  cur->val = cur->l->val + cur->r->val;
}

int query(int l, int r, int wl, int wr, pnode_t cur) {
  if(l > r || r < wl || l > wr) {
    return 0;
  }
  if(wl <= l && r <= wr) {
    return cur->val;
  }
  int mid = (l + r) >> 1;
  return query(l, mid, wl, wr, cur->l) + query(mid + 1, r, wl, wr, cur->r);
}

int search(int l, int r, int k, pnode_t cur_l, pnode_t cur_r) {
  if(l == r) {
    return l;
  }
  int mid = (l + r) >> 1;
  int val = cur_r->l->val - cur_l->l->val;
  // cerr << l << " " << r << " " << k << ": " << val << "\n";
  if(k <= val) {
    return search(l, mid, k, cur_l->l, cur_r->l);
  }
  return search(mid + 1, r, k - val, cur_l->r, cur_r->r);
}

void print(int l, int r, pnode_t cur) {
  cerr << l << " " << r << ": " << cur->val << "\n";
  if (l == r) {
    return;
  }
  int mid = (l + r) >> 1;
  print(l, mid, cur->l);
  print(mid + 1, r, cur->r);
}

int root_count = 0;
pnode_t roots[MxN];

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n, q, l, r, k;
  cin >> n >> q;
  build(1, n, roots[0]);
  vector<int> c;
  for(int i=1; i<=n; ++i) {
    cin >> a[i];
    c.emplace_back(a[i]);
  }
  sort(c.begin(), c.end());
  c.resize(unique(c.begin(), c.end()) - c.begin());
  for(int i=1; i<=n; ++i) {
    update(1, n, upper_bound(c.begin(), c.end(), a[i]) - c.begin(), 1, roots[i], roots[i - 1]);
  }
  while(q--) {
    cin >> l >> r >> k;
    cout << c[search(1, n, k, roots[l - 1], roots[r]) - 1] << "\n";
  }
  return 0;
}