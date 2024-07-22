#include <bits/stdc++.h>

using namespace std;
using ll = long long;

inline void solve() {
  int n;
  string s, answer;
  cin >> n >> s;
  int l = 0, r = n-1, bad = 0, good = 0;
  for(; l<r; ++l, --r) {
    bad += (s[l] != s[r]);
    good += (s[l] == s[r]);
  }
  for(int i=0; i<=n; ++i) {
    answer += "0";
  }
  if(n % 2 == 0) {
    for(int i=0; i<=good; ++i) {
      answer[bad + 2 * i] = '1';
    }
  }
  else {
    for(int i=bad; i<2+bad+2*good; ++i) {
      answer[i] = '1';
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