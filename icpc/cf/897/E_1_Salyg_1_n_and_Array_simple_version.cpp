#include <bits/stdc++.h>

using namespace std;
using ll = long long;

inline int ask(int v) {
  cout << "? " << v << "\n";
  cout.flush();
  int res;
  cin >> res;
  return res;
}

inline void print_answer(int v) {
  cout << "! " << v << "\n";
  cout.flush();
  return ;
}

inline void solve() {
  int n, k;
  cin >> n >> k;
  int xr = 0;
  for(int i=1; i<=n-k+1; i+=k) {
    xr ^= ask(i);
  }
  if(n % k == 0) {
    print_answer(xr);
    return ;
  }
  for(int i=(n / k) * k + 1; i<=n; ++i) {
    xr ^= ask(i - k + 1);
  }
  print_answer(xr);
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