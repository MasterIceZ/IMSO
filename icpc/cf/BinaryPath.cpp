#include <bits/stdc++.h>

using namespace std;
using ll = long long;

inline void solve() {
  int n;
  string s, t, answer = "";
  cin >> n >> s >> t;
  s = " " + s; t = " " + t;
  int state = 0;
  for(int i=1; i<=n; ++i) {
    if(!state && s[i] == '0') {
      answer += s[i];
    }
    else if(!state && i + 1 <= n && s[i] == '1' && t[i] == '0' && s[i + 1] == '1') {
      answer += s[i];
      answer += t[i];
      state = 1;
    }
    else {
      answer += t[i];
      state = 1;
    }
  }
  cout << answer;
  // assert((int) answer.size() == n + 1);
  
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) {
    solve();
    cout << "\n";
  }
  return 0;
}