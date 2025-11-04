#include <iostream>

const int MxN = 100010;

struct lazy_segment_tree {
  long long t[MxN << 2], lz[MxN << 2];

  void push_lazy(int l, int r, int idx) {
    if(lz[idx] == 0ll) {
      return ;
    }
    t[idx] += (r - l + 1ll) * lz[idx];
    if(l != r) {
      lz[idx << 1] = lz[idx];
      lz[(idx << 1) | 1] = lz[idx];
    }
    lz[idx] = 0ll;
  }

  void update(int l, int r, int wl, int wr, long long v, int idx) {
    push_lazy(l, r, idx);
    if(l > wr || r < wl) {
      return ;
    }
    if(wl <= l && r <= wr) {
      lz[idx] = v;
      push_lazy(l, r, idx);
      return ;
    }
    int mid = (l + r) >> 1;
    update(l, mid, wl, wr, v, idx << 1);
    update(mid + 1, r, wl, wr, v, idx << 1 | 1);
    t[idx] = t[idx << 1] + t[idx << 1 | 1];
  }

  long long query(int l, int r, int wl, int wr, int idx) {
    
  }
};

signed main(int argc, char *argv[]) {

}