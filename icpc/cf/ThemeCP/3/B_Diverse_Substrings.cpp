#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
string s;

inline void solve() {
  cin >> n >> s;
  s = " " + s;
  int answer = 0;
  for(int i=1; i<=n; ++i) {
    vector<int> cnt(10, 0);
    int max_count = 0, cur_distinct = 0;
    for(int j=i; j<=n && max_count <= 10; ++j) {
      cnt[s[j] - '0'] += 1;
      cur_distinct += (cnt[s[j] - '0'] == 1);
      max_count = max(max_count, cnt[s[j] - '0']);
      if(max_count <= cur_distinct) {
        answer += 1;
      }
    }
  }
  cout << answer << "\n";
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