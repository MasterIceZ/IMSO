#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  ll m, n, x, sm = 0ll, sn = 0ll;
  cin >> m >> n;
  sm += m;
  sn += n;
  for(int i=1; i<=m; ++i) {
    cin >> x;
    sm += x;
  }
  for (int i=1; i<=n; ++i) {
    cin >> x;
    sn += x;
  }
  if(sn == sm) {
    cout << "TIED\n";
  }
  else if(sn > sm) {
    cout << "BOB\n";
  }
  else {
    cout << "ALICE\n";
  }
  return 0;
}
