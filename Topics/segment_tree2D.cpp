#include <bits/stdc++.h>

using namespace std;

const int MxN = 1010;

template<class T>
struct segment_tree{
  T tree[MxN << 2];
  void update(int l, int r, int id, T v, int idx){
    if(l > r || id < l || id > r) {
      return;
    }
    if(l == r) {
      tree[idx] = v;
    }
    int mid = (l + r) >> 1;
    update(l, mid, id, v, idx << 1);
    update(mid + 1, r, id, v, idx << 1 | 1);
    tree[idx] = tree[idx << 1] + tree[idx << 1 | 1];
  }
  T query(int l, int r, int wl, int wr, int idx) {
    if(l > r || l > wr || r < wl) {
      return 0;
    }
    if(wl <= l && r <= wr) {
      return tree[idx];
    }
    int mid = (l + r) >> 1;
    return query(l, mid, wl, wr, idx << 1) + query(mid + 1, r, wl, wr, idx << 1);
  }
  segment_tree operator + (const segment_tree &L, const segment_tree &R) {
    segment_tree<T> response;
    seg
    return response;
  }
};

segment_tree<segment_tree<int>> seg;

int main() {
  seg.update()
  return 0;
}