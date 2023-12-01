#include <bits/stdc++.h>

using namespace std;

const int MxN = 200020;
int a[MxN];

inline void solve() {
  int n;
  cin >> n;
  for(int i=1; i<=n; ++i) {
    cin >> a[i];
  }
  int idx = min_element(a + 1, a + n + 1) - (a + 1);
  int res = idx;
  if(!is_sorted(a + idx + 1, a + n + 1)) {
    res = -1;
  }
  cout << res;
  return ;
}

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) {
    solve();
    cout << "\n";
  }
  return 0;
}