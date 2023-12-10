#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 100010;

struct query_t {
  int idx, l, r;
  query_t(int _idx, int _l, int _r):
    idx(_idx), l(_l), r(_r) {}
};

struct node_t {
  ll sum=0ll, maxx=-1e18-100ll, pref_max=-1e18-100ll, suf_max=-1e18-100ll;
  node_t() {}
  node_t(ll v) {
    sum = maxx = pref_max = suf_max = v;
  }
};

struct segment_tree {
  node_t t[MxN << 2];
  node_t merge_node(node_t l, node_t r) {
    node_t res;
    res.sum = l.sum + r.sum;
    res.maxx = max({l.maxx, r.maxx, l.suf_max + r.pref_max});
    res.pref_max = max(l.pref_max, l.sum + r.pref_max);
    res.suf_max = max(r.suf_max, r.sum + l.suf_max);
    return res;
  }
  void build(int l, int r, int idx) {
    if(l > r) {
      return ;
    }
    if(l == r) {
      t[idx] = node_t(0ll);
      return ;
    }
    int mid = (l + r) >> 1;
    build(l, mid, idx << 1);
    build(mid + 1, r, idx << 1 | 1);
    t[idx] = merge_node(t[idx << 1], t[idx << 1 | 1]);
  }
  void update(int l, int r, int id, ll v, int idx) {
    if(l > r || l > id || r < id) {
      return ;
    }
    if(l == r) {
      t[idx] = node_t(v);
      return ;
    }
    int mid = (l + r) >> 1;
    update(l, mid, id, v, idx << 1);
    update(mid + 1, r, id, v, idx << 1 | 1);
    t[idx] = merge_node(t[idx << 1], t[idx << 1 | 1]);
  }
  node_t query(int l, int r, int wl, int wr, int idx) {
    if(l > r || l > wr || r < wl) {
      return node_t();
    }
    if(wl <= l && r <= wr) {
      return t[idx];
    }
    int mid = (l + r) >> 1;
    return merge_node(query(l, mid, wl, wr, idx << 1), query(mid + 1, r, wl, wr, idx << 1 | 1));
  }
} seg;

vector<pair<int, ll>> line[MxN];
vector<query_t> query[MxN];
ll answer[MxN], x;

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n, m, q, k, s, t;
  cin >> n >> m;
  for(int i=1, l, r; i<=m; ++i) {
    cin >> l >> r >> x;
    line[l].emplace_back(i, x);
    line[r + 1].emplace_back(i, 0ll);
  }
  cin >> q;
  for(int i=1; i<=q; ++i) {
    cin >> k >> s >> t;
    query[k].emplace_back(i, s, t);
  }
  seg.build(1, m, 1);
  for(int i=1; i<=n; ++i) {
    for(auto x: line[i]) {
      seg.update(1, m, x.first, x.second, 1);
    }
    for(auto x: query[i]) {
      answer[x.idx] = seg.query(1, m, x.l, x.r, 1).maxx;
    }
  }
  for(int i=1; i<=q; ++i) {
    cout << answer[i] << "\n";
  }
  return 0;
}