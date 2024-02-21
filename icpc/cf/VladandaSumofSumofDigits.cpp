#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll ps[200020];

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int t;
  cin >> t;
  for(int i=1; i<=200000; ++i) {
    int j = i, sum = 0;
    while(j >= 10) {
      sum += (j % 10);
      j /= 10;
    }
    sum += j;
    ps[i] = ps[i - 1] + sum;
  }
  while(t--) {
    ll x;
    cin >> x;
    cout << ps[x] << "\n";
  }
  return 0;
}