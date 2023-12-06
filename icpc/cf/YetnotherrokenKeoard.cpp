#include <bits/stdc++.h>

using namespace std;
using ll = long long;

inline void solve() {
  string s;
  cin >> s;
  vector<pair<int, char>> a, b, c;
  for(int i=0; i<(int) s.size(); ++i) {
    if(isupper(s[i])) {
      if(s[i] == 'B') {
        if(!a.empty()) {
          a.pop_back();
        }
      }
      else {
        a.emplace_back(i, s[i]);
      }
    }
    else {
      if(s[i] == 'b') {
        if(!b.empty()) {
          b.pop_back();
        }
      }
      else {
        b.emplace_back(i, s[i]);
      }
    }
  }
  for(auto x: a) {
    c.emplace_back(x);
  }
  for(auto x: b) {
    c.emplace_back(x);
  }
  sort(c.begin(), c.end());
  for(auto x: c) {
    cout << ((char) x.second);
  }
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