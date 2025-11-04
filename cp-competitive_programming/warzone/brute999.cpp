#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  long long n, l, r;
  int q;
  cin >> n >> q;
  vector<bool> b(n+1, true);
  while(q--) {
    cin >> l >> r;
    for(long long i=l; i<=r; ++i) {
      b[i] = false;
    }
    long long c = 0ll;
    for(long long i=1; i<=n; ++i) {
      c += b[i];
    }
    cout << c << "\n";
  }
  return 0;
}