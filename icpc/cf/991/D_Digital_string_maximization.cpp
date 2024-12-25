#include <bits/stdc++.h>

using namespace std;
using ll = long long;

inline void solve() {
  string s;
  cin >> s;
  int n = (int) s.size();
  s = " " + s;
  for(int i=2; i<=n; ++i) {
    int best_pos = i;
    char val = s[i];
    for(int j=1; j<=s[i] && i-j>=1; ++j) {
      char t = s[i] - j;
      int p = i - j;
      if(s[p] < t) {
        val = t;
        best_pos = p;
      }
    }
    s[i] = val;
    for(int j=i; j>best_pos; --j) {
      swap(s[j], s[j - 1]);
    }
  }
  cout << s << "\n";
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