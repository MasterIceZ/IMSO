#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 200020;

template<typename T>
struct fenwick_tree {
  T *t;
  int n;
  fenwick_tree(int _n) {
    n = _n;
    t = (int *) calloc(n, sizeof (int));
  }
  void update(int idx, int v) {
    for(; idx<n; idx+=idx&-idx) {
      t[idx] += v;
    }
  }
  int query(int idx) {
    int res = 0;
    for(; idx>0; idx-=idx&-idx) {
      res += t[idx];
    }
    return res;
  }
};

int a[MxN];

int make_sum(int val, int t) {
  if(t == 0 || val < 10) {
    return val;
  }
  int go_next = 0;
  while(val > 0) {
    go_next += val % 10;
    val /= 10;
  }
  return make_sum(go_next, t - 1);
}

inline void solve() {
  int n, q;
  cin >> n >> q;
  fenwick_tree<int> fw(n + 1);
  for(int i=1; i<=n; ++i) {
    cin >> a[i];
  }
  while(q--) {
    int opr;
    cin >> opr;
    if(opr == 1) {
      int l, r;
      cin >> l >> r;
      fw.update(l, 1);
      fw.update(r + 1, -1);
    }
    else {
      int x;
      cin >> x;
      cout << make_sum(a[x], fw.query(x)) << "\n";
    }
  }
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