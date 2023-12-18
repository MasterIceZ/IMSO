#include <bits/stdc++.h>

using namespace std;
using ll = long long;

inline void solve() {
  string s;
  cin >> s;
  int n = (int) s.size();
  s = " " + s;
  vector<vector<ll>> cnt(2, vector<ll> (n + 2, 0ll));
  for(int i=1; i<=n; ++i) {
    cnt[s[i] - '0'][i] += 1ll;
    cnt[0][i] += cnt[0][i - 1];
    cnt[1][i] += cnt[1][i - 1];
  }
  ll cnt_01 = 0ll, cnt_10;
  for(int i=1; i<=n; ++i) {
    if(s[i] == '1') {
      cnt_01 += cnt[0][i];
    }
    else {
      cnt_10 += cnt[1][i];
    }
  }
  cout << (cnt_01 == cnt_10);
  return ;
}

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int t = 1;
  while(t--) {
    solve();
    cout << "\n";
  }
  return 0;
}