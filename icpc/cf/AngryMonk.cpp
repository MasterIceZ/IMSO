#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 100010;

int a[MxN];

inline void solve() {
  int n, k;
  cin >> n >> k;
  int answer = 0ll;
  for(int i=1; i<=k; ++i) {
    cin >> a[i];
    answer += 2 * (a[i] - 1);
  }
  answer += k - 1;
  answer -= 2 * (*max_element(a + 1, a + k + 1) - 1);
  cout << answer << "\n";
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