#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 200020;

ll a[MxN];

inline void solve() {
  int n;
  cin >> n;
  for(int i=1; i<=n; ++i) {
    cin >> a[i];
  }
  int l = 1;
  while(l <=n && a[l] == 0) {
    l++;
  }
  ll answer = 0ll;
  for(ll i= (ll) l; i<=(ll) n - 1ll; ++i) {
    if(a[i] != 0) {
      answer += a[i];
    }
    else {
      answer += 1;
    }
  }
  cout << answer << "\n";
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