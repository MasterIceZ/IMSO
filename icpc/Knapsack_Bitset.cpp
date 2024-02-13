#include <bits/stdc++.h>

using namespace std;

const int MxW = 10010;

bitset<MxW> dp;

int main() {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  dp[0] = true;
  for(int i=1, x, w; i<=n; ++i) {
    cin >> x >> w;
    dp |= dp << x;
  }
  int answer = 0;
  for(int i=m; i>=0; --i) {
    if(dp[i] == false) {
      continue;
    }
    answer = i;
    break;
  }
  cout << answer << "\n";
  return 0;
}