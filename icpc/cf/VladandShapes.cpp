#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector<string> s(n + 1);
    for(int i=1; i<=n; ++i) {
      cin >> s[i];
      s[i] = " " + s[i];
    }
    int cnt = 0;
    pair<int, int> t = make_pair(n, n), b = make_pair(1, 1);
    for(int i=1; i<=n; ++i) {
      for(int j=1; j<=n; ++j) {
        if(s[i][j] == '1') {
          cnt++;
          t = min(t, make_pair(i, j));
          b = max(b, make_pair(i, j));
        }
      }
    }
    if((t.first - b.first) * (t.second - b.second) == cnt) {
      cout << "SQUARE\n";
    } else {
      cout << "TRIANGLE\n";
    }
  }
  return 0;
}