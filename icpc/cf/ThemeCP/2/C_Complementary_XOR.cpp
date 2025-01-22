#include <bits/stdc++.h>

using namespace std;
using ll = long long;

inline void solve() {
  int n, cnt_one = 0;
  string s, t;
  cin >> n >> s >> t;
  s = " " + s;
  t = " " + t;
  bool ok = (s[1] == t[1]);
  for(int i=1; i<=n; ++i) {
    if(ok != (s[i] == t[i])) {
      cout << "NO\n";
      return ;
    }
    cnt_one += (s[i] == '1');
  }
  vector<pair<int, int>> answer;
  for(int i=1; i<=n; ++i) {
    if(s[i] == '0') {
      continue;
    }
    answer.emplace_back(i, i);
  }
  cout << "YES\n";
  if(ok != (cnt_one % 2 == 0)) {
    answer.emplace_back(1, 1);
    answer.emplace_back(2, 2);
    answer.emplace_back(1, 2);
  }
  cout << answer.size() << "\n";
  for(auto [x, y]: answer) {
    cout << x << " " << y << "\n";
  }
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