#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define sz(x) (x).size()

const ll LINF = 1e18 + 100ll;
const int MxN = 200020;

int a[MxN];

template <class Node, class Tag>
struct LazySegTree {
  int n;
  vector<Node> t;
  vector<Tag> lz;
  LazySegTree() {}
  LazySegTree(int n, Node v = Node()) { init(n, v); }
  template <class T>
  LazySegTree(const vector<T> &a) { init(a); }
  void init(int n, Node v = Node()) { init(vector<Node>(n, v)); }
  template <class T>
  void init(const vector<T> &a) {
    n = sz(a);
    t.assign(4 << 31 - __builtin_clz(n), Node());
    lz.assign(4 << 31 - __builtin_clz(n), Tag());
    function<void(int, int, int)> build = [&](int l, int r, int i) {
      if (l == r)
        return void(t[i] = a[l]);
      int m = (l + r) / 2;
      build(l, m, i * 2);
      build(m + 1, r, i * 2 + 1);
      pull(i);
    };
    build(0, n - 1, 1);
  }
  void pull(int i) {
    t[i] = t[i * 2] + t[i * 2 + 1];
  }
  void apply(int l, int r, int i, const Tag &v) {
    t[i].apply(l, r, v);
    lz[i].apply(l, r, v);
  }
  void push(int l, int r, int i) {
    int m = (l + r) / 2;
    apply(l, m, i * 2, lz[i]);
    apply(m + 1, r, i * 2 + 1, lz[i]);
    lz[i] = Tag();
  }
  void modify(int l, int r, int i, int x, const Node &v) {
    if (x < l || r < x)
      return;
    if (l == r)
      return void(t[i] = v);
    int m = (l + r) / 2;
    push(l, r, i);
    modify(l, m, i * 2, x, v);
    modify(m + 1, r, i * 2 + 1, x, v);
    pull(i);
  }
  void modify(int x, const Node &v) {
    modify(0, n - 1, 1, x, v);
  }
  void update(int l, int r, int i, int x, int y, const Tag &v) {
    if (y < l || r < x)
      return;
    if (x <= l && r <= y)
      return apply(l, r, i, v);
    int m = (l + r) / 2;
    push(l, r, i);
    update(l, m, i * 2, x, y, v);
    update(m + 1, r, i * 2 + 1, x, y, v);
    pull(i);
  }
  void update(int x, int y, const Tag &v) {
    update(0, n - 1, 1, x, y, v);
  }
  Node query(int l, int r, int i, int x, int y) {
    if (y < l || r < x)
      return Node();
    if (x <= l && r <= y)
      return t[i];
    int m = (l + r) / 2;
    push(l, r, i);
    return query(l, m, i * 2, x, y) + query(m + 1, r, i * 2 + 1, x, y);
  }
  Node query(int x, int y) {
    return query(0, n - 1, 1, x, y);
  }
  template <class F>
  int findfirst(int l, int r, int i, int x, int y, const F &f) {
    if (y < l || r < x || !f(t[i]))
      return -1;
    if (l == r)
      return l;
    int m = (l + r) / 2;
    push(l, r, i);
    int res = findfirst(l, m, i * 2, x, y, f);
    if (res == -1)
      res = findfirst(m + 1, r, i * 2 + 1, x, y, f);
    return res;
  }
  template <class F>
  int findfirst(int x, int y, const F &f) {
    return findfirst(0, n - 1, 1, x, y, f);
  }
  template <class F>
  int findlast(int l, int r, int i, int x, int y, const F &f) {
    if (y < l || r < x || !f(t[i]))
      return -1;
    if (l == r)
      return l;
    int m = (l + r) / 2;
    push(l, r, i);
    int res = findlast(m + 1, r, i * 2 + 1, x, y, f);
    if (res == -1)
      res = findlast(l, m, i * 2, x, y, f);
    return res;
  }
  template <class F>
  int findlast(int x, int y, const F &f) {
    return findlast(0, n - 1, 1, x, y, f);
  }
};
struct AddTag {
  ll val;
  AddTag() : val(0) {}
  AddTag(ll v) : val(v) {}
  void apply(int l, int r, const AddTag &v)
  {
    val += v.val;
  }
};
struct MinNode {
  ll val;
  MinNode() : val(LINF) {}
  MinNode(ll v) : val(v) {}
  void apply(int l, int r, const AddTag &v) {
    val += v.val;
  }
  friend MinNode operator+(const MinNode &lhs, const MinNode &rhs) {
    return MinNode(min(lhs.val, rhs.val));
  }
};

inline void solve() {
  int n;
  cin >> n;
  for(int i=1; i<=n; ++i) {
    cin >> a[i];
    a[i]--;
  }
  LazySegTree<MinNode, AddTag> seg;
  seg.init(n);
  for(int i=1; i<=n; ++i) {
    ll t = min(seg.query(0, a[i] - 1).val, seg.query(a[i], n - 1).val);
    if(i == 1) {
      continue;
    }
    if(a[i] > a[i - 1]) {
      seg.update(0, n - 1, AddTag(1ll));
    }
    ll d = seg.query(a[i - 1], a[i - 1]).val;
    if(d > t) {
      seg.update(a[i - 1], a[i - 1], d - t);
    }
  }
  cout << seg.query(0, n - 1).val << "\n";
  return ;
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int q;
  cin >> q;
  while(q--) {
    solve();
    cout << "\n";
  }
  return 0;
}