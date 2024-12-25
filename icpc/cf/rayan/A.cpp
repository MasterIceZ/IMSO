#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) {
    ll a, b;
    cin >> a >> b;
    cout << a * b / __gcd(a, b) << "\n";
  }
  return 0 ;
}