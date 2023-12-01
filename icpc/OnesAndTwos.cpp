#include <bits/stdc++.h>

using namespace std;

const int MxN = 100010;

int n, a[MxN];

struct fenwick_tree {
  int *t, n;
  void update(int idx, int v) {
    for(; idx<=n; idx+=idx&-idx) {
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
  void build() {
    for(int i=1; i<=n; ++i) {
      t[i] += a[i];
      int nxt = i+(i&-i);
      if(nxt <= n) {
        t[nxt] += t[i];
      }
    }
  }
  fenwick_tree(int _n): n(_n) {
    t = (int *) calloc(n + 1, sizeof(int));
  }
};

inline void solve() {
  int q, opr, idx, v, s;
  cin >> n >> q;
  fenwick_tree fw(n);
  set<int> st;
  for(int i=1; i<=n; ++i) {
    cin >> a[i];
    if(a[i] == 1) {
      st.emplace(i);
    }
  }
  fw.build();
  while(q--) {
    cin >> opr;
    if(opr == 1) {
      cin >> s;
      bool can = false;
      if(st.size() > 0) {
        int l = *st.begin(), r = *(--st.end());
        if(s <= max(fw.query(r), fw.query(n) - fw.query(l - 1))) {
          can = true;
        }
      }
      int sum = fw.query(n);
      if(sum >= s && sum % 2 == s % 2) {
        can = true;
      }
      cout << (can ? "YES": "NO") << "\n";
    }
    else {
      cin >> idx >> v;
      if(a[idx] == v) {
        continue;
      }
      if(a[idx] == 1) {
        fw.update(idx, 1);
        st.erase(idx);
      }
      else {
        fw.update(idx, -1);
        st.emplace(idx);
      }
      a[idx] = v;
    }
  }
  return ;
}

signed main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}