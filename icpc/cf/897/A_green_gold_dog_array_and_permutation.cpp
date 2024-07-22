#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 40040;

pair<int, int> a[MxN];
int answer[MxN];

inline void solve() {
  int n;
  cin >> n;
  for(int i=1; i<=n; ++i) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a + 1, a + n + 1);
  for(int i=1; i<=n; ++i) {
    answer[a[i].second] = n - i + 1;
  }
  for(int i=1; i<=n; ++i) {
    cout << answer[i] << " ";
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