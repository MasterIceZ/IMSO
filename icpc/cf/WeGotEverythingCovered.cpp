#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) {
    int n, k;
    cin >> n >> k;
    string s, u;
    for(int i=0; i<=k-1; ++i) {
      s += (char) (i + 'a');
    }
    for(int i=1; i<=n; ++i) {
      u += s;
    }
    cout << u << "\n";
  }
  return 0;
}