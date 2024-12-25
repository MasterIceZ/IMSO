#include <bits/stdc++.h>

using namespace std;
using ll = long long;

inline void solve() {
  string s;
  cin >> s;
  int n = (int) s.size();
  s = " " + s;
  vector<int> cnt(10, 0);
  int sum_dig = 0;
  for(int i=1; i<=n; ++i) {
    cnt[s[i] - '0']++;
    sum_dig += s[i] - '0';
  }
  sum_dig %= 9;
  for(int i=0; i<=cnt[2]; ++i) {
    for(int j=0; j<=cnt[3]; ++j) {
      int new_tot = sum_dig + (i * 2 + j * 6);
      if(new_tot % 9 == 0) {
        cout << "YES\n";
        return ;
      }
    }
  }
  cout << "NO\n";
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