#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) {
    int x, y;
    cin >> x >> y;
    cout << (y >= -1 ? "YES": "NO") << "\n";
  }
  return 0;
}