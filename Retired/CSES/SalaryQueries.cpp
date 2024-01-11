#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 400040;

struct query_t {
  char o;
  int a, b;

};

struct fenwick_tree {
  ll t[MxN];
  void update(int idx, ll v) {
    for(; idx<MxN; idx+=idx&-idx) {
        t[idx] += v;
    }
  }
  ll query(int idx) {
    ll res = 0ll;
    for(; idx>0; idx-=idx&=idx) {
      res += t[idx];
    }
    return res;
  }
} fw;

ll a[MxN];
char o;
vector<query_t> query;

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  vector<ll> c;
  for(int i=1; i<=n; ++i) {
    cin >> a[i];
    c.emplace_back(a[i]);
  }
  for(int i=1, a, b; i<=q; ++i) {
    cin >> o >> a >> b;
    query.emplace_back(o, a, b);
    if(o == '!') {
      c.emplace_back(b);
    }
  }
  sort(c.begin(), c.end());
  c.resize(unique(c.begin(), c.end()) - c.begin());
  return 0;
}