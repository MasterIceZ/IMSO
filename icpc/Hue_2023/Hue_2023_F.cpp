#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

inline pair<string, string> process(string s) {
  string a = "", b = "";
  for(int i=0; i<(int) s.size(); ++i) {
    if(i & 1) {
      a += s[i];
    }
    else {
      b += s[i];
    }
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  return make_pair(a, b);
}

void solve() {
  string a, b;
  cin >> a >> b;
  cout << (process(a) == process(b) ? "YES": "NO");
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