#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &x: v) {
      cin >> x;
    }
    array<int, 2> mx = {0, 0};
    for(int i=0; i<n; ++i) {
      mx[i % 2] = max(mx[i % 2], v[i]);
    }
    int even = n / 2;
    int odd = even + (n % 2 == 1);
    cout << max(mx[0] + odd, mx[1] + even) << "\n";
  }
  return 0;
}