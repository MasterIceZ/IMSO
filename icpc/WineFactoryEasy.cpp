#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 500050;

int n, a[MxN], b[MxN];
ll c[MxN], v[MxN], suf_v[MxN], z;

struct lazy_segment_tree {
  ll t[MxN << 2], lzy[MxN << 2];
  inline ll merge_node(ll l, ll r) {
    return max(l, r);
  }
  void build(int l, int r, int idx) {
    if(l > r) {
      return ;
    }
    if(l == r) {
      t[idx] = suf_v[l];
      return ;
    }
    int mid = (l + r) >> 1;
    build(l, mid, idx << 1);
    build(mid + 1, r, idx << 1 | 1);
    t[idx] = merge_node(t[idx << 1], t[idx << 1 | 1]);
  }
  inline void push_lazy(int l, int r, int idx) {
    if(lzy[idx] == 0ll || l > r) {
      return ;
    }
    t[idx] += lzy[idx];
    if(l != r) {
      lzy[idx << 1] += lzy[idx];
      lzy[idx << 1 | 1] += lzy[idx];
    }
    lzy[idx] = 0ll;
  }
  void update(int l, int r, int wl, int wr, ll v, int idx) {
    push_lazy(l, r, idx);
    if(l > r || l > wr || r < wl) {
      return ;
    }
    if(wl <= l && r <= wr) {
      lzy[idx] += v;
      push_lazy(l, r, idx);
      return ;
    }
    int mid = (l + r) >> 1;
    push_lazy(l, r, idx);
    update(l, mid, wl, wr, v, idx << 1);
    update(mid + 1, r, wl, wr, v, idx << 1 | 1);
    t[idx] = merge_node(t[idx << 1], t[idx << 1 | 1]);
  }
} seg;

inline void update_tower(int p, int x, int y, ll z, ll &sum) {
  sum -= a[p];
  seg.update(1, n, 1, p, -v[p], 1);
  a[p] = x;
  b[p] = y;
  v[p] = a[p] - b[p];
  sum += a[p];
  seg.update(1, n, 1, p, v[p], 1);
}

inline ll query_tower(ll sum) {
  return sum - max(0ll, seg.t[1]);
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int q, p, x, y;
  cin >> n >> q;
  for(int i=1; i<=n; ++i) {
    cin >> a[i];
  }
  for(int i=1; i<=n; ++i) {
    cin >> b[i];
  }
  for(int i=1; i<=n-1; ++i) {
    cin >> c[i];
  }
  for(int i=n-1; i>=1; --i) {
    v[i] = a[i] - b[i];
    suf_v[i] = v[i] + suf_v[i + 1];
  }
  ll sum = accumulate(a + 1, a + n + 1, 0ll);
  seg.build(1, n, 1);
  while(q--) {
    cin >> p >> x >> y >> z;
    update_tower(p, x, y, z, sum);
    cout << query_tower(sum) << "\n";
  }
  return 0;
}