#include <bits/stdc++.h>

using namespace std;

inline void solve() {
  int n;
  cin >> n;
  if(n - 3 > 0 && n - 3 != 1 && n - 3 != 2 && (n - 3) % 3 != 0) {
    cout << "YES\n";
    cout << "2 1 " << n - 3;
  }
  else if(n - 6 > 0 && n - 6 != 2 && n - 6 != 4 && (n - 6) % 3 != 0) {
    cout << "YES\n";
    cout << "2 4 " << n - 6;
  }
  else {
    cout << "NO";
  }
  return;
}

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int t = 1;
  cin >> t;
  while(t--) {
    solve();
    cout << "\n";
  }
  return 0;
}