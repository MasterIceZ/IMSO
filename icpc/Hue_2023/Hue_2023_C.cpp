#include <bits/stdc++.h>

using namespace std;

const int di[] = {0, 1, -1, 1, -1, 0};
const int dj[] = {1, 1, 0, 0, -1, -1};

void solve() {
  int n;
  cin >> n;
  cout << "YES\n" << 7 * n << "\n";
  for(int i=1, x, y; i<=n; ++i) {
    cin >> x >> y;
    cout << x << " " << y << " 3\n";
    for(int k=0; k<6; ++k) {
      cout << x + di[k] << " " << y + dj[k] << " 2\n";
    }
  }
  return ;
}

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}