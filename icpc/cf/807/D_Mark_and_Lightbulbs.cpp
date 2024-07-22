#include <bits/stdc++.h>

using namespace std;
using ll = long long;

inline void solve() {
  int n;
  string s, t;
  cin >> n >> s >> t;
  s = " " + s;
  t = " " + t;
  vector<ll> cs, ct;
  for(int i=1; i<=n - 1; ++i) {
    if(s[i] != s[i + 1]) {
      cs.emplace_back((ll) i);
    }
    if(t[i] != t[i + 1]) {
      ct.emplace_back((ll) i);
    }
  }
  if(s[1] != t[1] || s.back() != t.back() || cs.size() != ct.size()) {
    cout << "-1\n";
    return ;
  }
  ll answer = 0ll;
  for(int i=0; i<(int) cs.size(); ++i) {
    answer += abs(cs[i] - ct[i]);
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