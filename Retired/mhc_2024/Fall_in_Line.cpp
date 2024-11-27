#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(int case_cnt) {
  int n;
  cin >> n;
  map<int, int> mp;
  for(int i=1, a, b; i<=n; ++i) {
    cin >> a >> b;
    mp[a - b]++;
  }
  int answer = n;
  for(auto [key, val]: mp) {
    answer = min(answer, n - val);
  }
  cout << "Case #" << case_cnt << ": " << answer << "\n";
  return ;
}

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int t, c = 0;
  cin >> t;
  while(t--) {
    solve(++c);
  }
  return 0;
}