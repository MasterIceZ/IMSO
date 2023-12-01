#include <bits/stdc++.h>

using namespace std;
using ll = long long;

map<int, ll> c;

inline void solve() {
  c.clear();
  int n;
  ll answer = 0ll;
  cin >> n;
  for(int i=1, x; i<=n; ++i) {
    cin >> x;
    answer += c[x];
    c[x] += 1ll;
    if(x <= 2) {
      answer += c[3 - x];
    }
  }
  cout << answer;
  return ;
}

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) {
    solve();
    cout << "\n";
  }
  return 0;
}