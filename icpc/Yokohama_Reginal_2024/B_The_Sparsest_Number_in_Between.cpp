#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  ll l, r;
  cin >> l >> r;
  ll minn = l;
  while(true) {
    ll adding = (l & -l);
    if(l + adding > r) {
      break;
    }
    l += adding;
    if(__builtin_popcountll(l) < __builtin_popcountll(minn)) {
      minn = l;
    }
  }
  cout << minn << "\n";
  return 0;
}

// 1010
// 1100