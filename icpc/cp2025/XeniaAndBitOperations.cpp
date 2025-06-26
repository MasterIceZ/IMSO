#include <iostream>

const int MxN = 1 << 18;

struct segment_tree {
  int t[MxN << 2];

  int merge_node(int l, int r, int state) {
    return (state == 1 ? (l | r) : (l ^ r));
  }
  void build(int l, int r, int idx, int state, int *a) {
    if(l > r) {
      return ;
    }
    if(l == r) {
      t[idx] = a[l];
      return ;
    }
    int mid = (l + r) >> 1;
    build(l, mid, idx << 1, !state, a);
    build(mid + 1, r, idx << 1 | 1, !state, a);
    t[idx] = merge_node(t[idx << 1], t[idx << 1 | 1], state);
  }
  void update(int l, int r, int id, int v, int idx, int state) {
    if(l > r || l > id || r < id) {
      return ;
    }
    if(l == r) {
      t[idx] = v;
      return ;
    }
    int mid = (l + r) >> 1;
    update(l, mid, id, v, idx << 1, !state);
    update(mid + 1, r, id, v, idx << 1 | 1, !state);
    t[idx] = merge_node(t[idx << 1], t[idx << 1 | 1], state);
  }
  int query() {
    return t[1];
  }
};

segment_tree seg;
int a[MxN];

signed main(int argc, char *argv[]) {
  std::cin.tie(nullptr)->std::ios_base::sync_with_stdio(false);
  int t, m;
  std::cin >> t >> m;
  int n = (1 << t) - 1;
  for(int i=0; i<=n; ++i) {
    std::cin >> a[i];
  }
  seg.build(0, n, 1, t & 1, a);
  while(m--) {
    int p, b;
    std::cin >> p >> b;
    p--;
    seg.update(0, n, p, b, 1, t & 1);
    std::cout << seg.query() << "\n";
  }
  return 0;
}