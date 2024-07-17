#include <bits/stdc++.h>

using namespace std;
using ll = long long;

inline void solve() {
  string a, b;
  cin >> a >> b;
  int answer = (int) a.size() + (int) b.size();
  for(int i=0; i<(int) b.size(); ++i) {
    int pos = i;
    for(int j=0; j<(int) a.size(); ++j) {
      if(pos < (int) b.size() && a[j] == b[pos]) {
        ++pos;
      }
    }
    int del = pos - i;
    answer = min(answer, (int) a.size() + (int) b.size() - del);
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