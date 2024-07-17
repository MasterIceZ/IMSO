#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 1000010;

int a[MxN], b[MxN], mem[MxN];
ll dp[MxN];

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for(int i=1; i<=n; ++i) {
    cin >> a[i];
  }
  int max_num = *max_element(a + 1, a + n + 1);
  for(int i=0; i<=max_num; ++i) {
    mem[i] = 1e9 + 100;
  }
  for(int i=1; i<=n; ++i) {
    cin >> b[i];
    mem[a[i]] = min(mem[a[i]], a[i] - b[i]);
  }
  for(int i=1; i<=max_num; ++i) {
    mem[i] = min(mem[i - 1], mem[i]);
  }
  for(int i=1; i<=max_num; ++i) {
    if(mem[i] > i) {
      continue;
    }
    dp[i] = dp[i - mem[i]] + 1ll;
  }
  ll answer = 0ll;
  for(int i=1, c; i<=m; ++i) {
    cin >> c;
    int cnt = max(0, (c - max_num + mem[max_num] - 1) / mem[max_num]);
    c -= cnt * mem[max_num];
    answer += dp[c] + cnt;
  }
  cout << answer * 2<< "\n";
  return 0;
}