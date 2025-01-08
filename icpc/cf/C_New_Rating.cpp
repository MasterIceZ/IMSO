#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 1e9 + 100;

struct val_t {
  int a, b, c;
  val_t():
    a(-INF), b(-INF), c(0) {}
  int cal(int x, int y) {
    if(x < y) {
      return x + 1;
    }
    if(x > y) {
      return x - 1;
    }
    return x;
  }
  void update(int v) {
    a = max(cal(a, v), cal(b, v));
    b = max(b, c);
    c = cal(c, v);
  }
  int get() {
    return max(a, b);
  }
};

inline void solve() {
  int n;
  cin >> n;
  val_t v;
  for(int i=1, x; i<=n; ++i) {
    cin >> x;
    v.update(x);
  }
  cout << v.get() << "\n";
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