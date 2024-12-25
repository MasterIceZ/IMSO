#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 200020;

struct segment_tree {
  int t[MxN << 2];
  void build(int l, int r, int idx, int *arr) {
    if(l > r) {
      return ;
    }
    if(l == r) {
      t[idx] = arr[l];
      return ;
    }
    int mid = (l + r) >> 1;
    build(l, mid, idx << 1, arr);
    build(mid + 1, r, idx << 1 | 1, arr);
    t[idx] = __gcd(t[idx << 1], t[idx << 1 | 1]);
  }
  int query(int l, int r, int wl, int wr, int idx) {
    if(l > r || r < wl || l > wr) {
      return 0;
    }
    if(wl <= l && r <= wr) {
      return t[idx];
    }
    int mid = (l + r) >> 1;
    return __gcd(query(l, mid, wl, wr, idx << 1), query(mid + 1, r, wl, wr, idx << 1 | 1));
  }
} seg;

int a[MxN], diff[MxN];

inline void solve() {
  int n, q;
  cin >> n >> q;
  for(int i=1; i<=n; ++i) {
    cin >> a[i];
    if(i > 1) {
      diff[i - 1] = abs(a[i] - a[i - 1]);
    }
  }
  seg.build(1, n - 1, 1, diff);
  while(q--) {
    int l, r;
    cin >> l >> r;
    if(l == r) {
      cout << "0";
    }
    else {
      cout << seg.query(1, n - 1, l, r - 1, 1);
    }
    cout << " ";
  }
  cout << "\n";
  return ;
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}