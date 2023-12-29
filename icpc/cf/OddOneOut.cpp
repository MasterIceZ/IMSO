#include <bits/stdc++.h>

using namespace std;

inline void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  if(a == b) {
    cout << c;
  } else if(a == c) {
    cout << b;
  } else {
    cout << a;
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