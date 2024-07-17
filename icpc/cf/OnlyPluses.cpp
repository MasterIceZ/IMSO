#include <bits/stdc++.h>

using namespace std;
using ll = long long;

inline void solve() {
  int a, b, c, answer = 1;
  cin >> a >> b >> c;
  for(int i=0; i<=5; ++i) {
    for(int j=0; j<=5; ++j) {
      for(int k=0; k<=5; ++k) {
        if(i + j + k > 5) {
          continue;
        }
        answer = max(answer, (a + i) * (b + j) * (c + k));
      }
    }
  }
  cout << answer << "\n";
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