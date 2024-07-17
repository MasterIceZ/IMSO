#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 100010;
const int MxA = 200020;

struct fenwick_tree {
  ll t[MxA];
  void update(int idx, ll v) {
    for(; idx<MxA; idx+=idx&-idx) {
      t[idx] += v;
    }
  }
  ll query(int idx) {
    ll res = 0ll;
    for(; idx>0; idx-=idx&-idx) {
      res += t[idx];
    }
    return res;
  }
  void clear() {
    for(int i=0; i<MxA; ++i) {
      t[i] = 0ll;
    }
  }
} fw;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1), b(n + 1);
  multiset<int> msa, msb;
  for(int i=1; i<=n; ++i) {
    cin >> a[i];
    msa.emplace(a[i]);
  }
  for(int i=1; i<=n; ++i) {
    cin >> b[i];
    msb.emplace(b[i]);
  }
  if(msa != msb) {
    cout << "NO\n";
    return ;
  }
  auto inversion = [&](vector<int> &a) {
    ll res = 0ll;
    for(int i=1; i<=n; ++i) {
      res += fw.query(a[i]);
      fw.update(a[i], 1ll);
    }
    for(int i=1; i<=n; ++i) {
      fw.update(a[i], -1ll);
    }
    return res;
  };
  ll inv_a = inversion(a), inv_b = inversion(b);
  cout << ((inv_a % 2ll) == (inv_b % 2ll) ? "YES": "NO") << "\n";
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