#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 200020;

struct line_t {
  ll m, c;
  ll operator() (ll x) {
    if(m <= -1e18 - 100ll || c <= -1e18 - 100ll) {
      return -1e18 - 100ll;
    }
    return m * x + c;
  }
  line_t(ll _m, ll _c):
    m(_m), c(_c) {}
  line_t():
    m(-1e18 - 100ll), c(-1e18 - 100ll) {};
};



ll a[MxN], b[MxN], pref_sum[MxN], r[MxN];
vector<ll> c;

struct lichao_tree {
  line_t t[MxN << 2];
  void update(int l, int r, line_t line, int idx) {
    int mid = (l + r) >> 1;
    if(line(::r[mid]) > t[idx](::r[mid])) {
      swap(line, t[idx]);
    }
    bool gone = false;
    if(line(::r[l]) > t[idx](::r[l])) {
      update(l, mid, line, idx << 1);
    }
    if(line(::r[r]) > t[idx](::r[r])) {
      update(mid + 1, r, line, idx << 1 | 1);
    }
  }
  ll query(int l, int r, ll x, int idx) {
    ll res = t[idx](x);
    if (l == r) {
      return t[idx](x);
    }
    int mid = (l + r) >> 1;
    if(x <= ::r[mid]) {
      return max(res, query(l, mid, x, idx << 1));
    }
    else {
      return max(res, query(mid + 1, r, x, idx << 1 | 1));
    }
  }
  void clear(int l, int r, int idx) {
    t[idx] = line_t();
    if(l == r) {
      return ;
    }
    int mid = (l + r) >> 1;
    clear(l, mid, idx << 1);
    clear(mid + 1, r, idx << 1 | 1);
  }
} lct;

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for(int i=1; i<=n; ++i) {
    cin >> a[i];
    pref_sum[i] = pref_sum[i - 1] + a[i];
    c.emplace_back(a[i]);
  }
  sort(c.begin(), c.end());
  c.resize(unique(c.begin(), c.end()) - c.begin());
  for(int i=1; i<=n; ++i) {
    int idx = upper_bound(c.begin(), c.end(), a[i]) - c.begin();
    b[i] = idx;
    r[idx] = a[i];
  }
  int b_sz = (int) c.size();
  ll answer = 0ll, base = 0ll;
  for(ll i=1ll; i<=(ll) n; ++i) {
    base += a[i] * i;
  }
  for(ll i=1ll; i<=(ll) n; ++i) {
    answer = max(answer, (pref_sum[i - 1] - (a[i] * i)) + lct.query(1, b_sz, r[b[i]], 1));
    lct.update(1, b_sz, line_t(i, -pref_sum[i - 1]), 1);
  }
  lct.clear(1, b_sz, 1);
  for(ll i=(ll) n; i>=1ll; --i) {
    answer = max(answer, lct.query(1, b_sz, r[b[i]], 1) - ((a[i] * i) - pref_sum[i]));
    lct.update(1, b_sz, line_t(i, -pref_sum[i]), 1);
  }
  cout << answer + base << "\n";
  return 0;
}