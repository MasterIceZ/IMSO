#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 200020;

ll a[MxN], s[2];

inline void solve() {
  int n;
  cin >> n;
  s[0] = s[1] = 0;
  for(int i=1; i<=n; ++i) {
    cin >> a[i];
    s[i & 1] += a[i];
  }
  ll even_length = n / 2;
  ll odd_length = n - even_length;
  if(s[1] % odd_length == 0ll && s[0] % even_length == 0ll && s[1] / odd_length == s[0] / even_length) {
    cout << "YES";
  }
  else {
    cout << "NO";
  }
  cout << "\n";
  return ;
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}