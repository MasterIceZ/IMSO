#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 300030;

struct fenwick_tree {
  ll t[MxN];
  void update(int idx, ll v) {
    for(; idx<MxN; idx+=idx&-idx) {
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
};

int n, m, q, o, x[MxN];
ll v[MxN], rv[MxN];
set<ll> position;
fenwick_tree fw;
pair<int, ll> p[MxN];

inline ll get_update_value(ll v, ll dist) {
  return v * (dist * (dist - 1ll) / 2ll);
}

inline ll get_bound(int ps) {
  if(ps >= n) {
    return 0ll;
  }
  auto idx = position.lower_bound(ps);
  if(*idx == ps) {
    return 0ll;
  }
  ll dist = *idx - ps + 1ll;
  auto prev_idx = --position.lower_bound(ps);
  ll val;
  if(*prev_idx < 0 || *prev_idx >= n) {
    val = 0ll;
    assert(0);
  }
  else {
    val = rv[*prev_idx];
  }
  return get_update_value(val, dist);
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  cin >> n >> m >> q;
  for(int i=1; i<=m; ++i) {
    cin >> x[i];
    position.emplace(x[i]);
  }
  for(int i=1; i<=m; ++i) {
    cin >> v[i];
    p[i] = make_pair(x[i], v[i]);
    rv[x[i]] = v[i];
  }
  sort(p + 1, p + m + 1);
  for(int i=1; i<=m-1; ++i) {
    ll dist = p[i + 1].first - p[i].first;
    fw.update(p[i].first, get_update_value(p[i].second, dist));
  }
  
  while(q--) {
    cin >> o;
    if(o == 1) {
      int x;
      ll v;
      cin >> x >> v;
      auto idx = position.lower_bound(x);
      ll dist = *idx - x;
      fw.update(x, get_update_value(v, dist));
      auto prev_idx = --position.lower_bound(x);
      dist = x - *prev_idx;
      fw.update(*prev_idx, get_update_value(rv[*prev_idx], dist) - fw.query(*prev_idx) + fw.query(*prev_idx - 1));
      position.emplace(x);
      rv[x] = v;
    }
    else {
      int l, r;
      cin >> l >> r;
      cout << fw.query(r) - fw.query(l - 1) + get_bound(l) - get_bound(r + 1) << "\n";
    }
  }
  return 0;
}