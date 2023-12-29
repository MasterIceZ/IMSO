#include <bits/stdc++.h>

using namespace std;

inline void solve() {
  string s;
  for(int i=1; i<=3; ++i) {
    cin >> s;
    char answer = '!';
    int have = 6;
    for(auto x: s) {
      if(x != '?'){
        have -= (x - 'A' + 1);
      }
    }
    if(have != 0) {
      cout << ((char)(have + 'A' - 1));
    }
  }
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