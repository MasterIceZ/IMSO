#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 100010;
const ll INF = 1e18 + 100ll;

ll s, suffix_max[MxN];
pair<ll, ll> a[MxN], v[MxN];

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n;
  cin >> n >> s;
  ll minn = INF, maxx = -INF;
  for(int i=1; i<=n; ++i) {
    cin >> a[i].first >> a[i].second;
    a[i].first -= s;
    a[i].second -= s;
    minn = min({minn, a[i].first, a[i].second});
    maxx = max({maxx, a[i].first, a[i].second});
  }

  if(minn > 0) {
    // all at right 
    cout << maxx * 2ll << "\n";
    return 0;
  }
  if(maxx < 0) {
    // all at left
    cout << -minn * 2ll << "\n";
    return 0;
  }
  
  ll answer = INF;
  for(int _=1; _<=2; ++_) {
    int it = 0;
    for(int i=1; i<=n; ++i) {
      if(a[i].first > 0 && a[i].second < 0) {
        v[++it] = a[i];
      }
    }
    if(it == 0) {
      answer = 0ll;
      break;
    }
    sort(v + 1, v + it + 1);
    suffix_max[it + 1] = 0ll;
    for(int i=it; i>=1; --i) {
      suffix_max[i] = max(suffix_max[i + 1], -a[i].second);
    }
    ll cur_min = INF;
    for(int i=1; i<=it; ++i) {
      cur_min = min(cur_min, a[i].first + suffix_max[i + 1]);
    }
    answer = min(answer, cur_min);
    for(int i=1; i<=n; ++i) {
      a[i] = make_pair(a[i].second, a[i].first);
    }
  }

  cout << (answer + (maxx-minn)) * 2ll << "\n";
  return 0;
}