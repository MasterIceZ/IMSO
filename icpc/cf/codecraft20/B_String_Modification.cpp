#include <bits/stdc++.h>

using namespace std;
using ll = long long;

inline void solve() {
  int n;
  string s;
  cin >> n >> s;
  string answer = s;
  int able_k = 1;
  for(int i=2; i<=n; ++i) {
    string bck = s.substr(0, i - 1);
    if((n - i) % 2 == 0) {
      reverse(bck.begin(), bck.end());
    }
    string t = s.substr(i - 1, n - i + 1) + bck;
    if(t < answer) {
      answer = t;
      able_k = i;
    }
  }
  cout << answer << "\n" << able_k << "\n";
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