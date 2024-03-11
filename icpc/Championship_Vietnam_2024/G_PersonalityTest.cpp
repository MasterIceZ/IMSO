#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MxN = 5050;

string s[MxN];
int cnt[MxN];
vector<int> position[26][MxN];

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n, m, k, a = 0, b = 0;
  cin >> n >> m >> k;
  for(int i=1; i<=n; ++i) {
    cin >> s[i];
    s[i] = " " + s[i];
    for(int i=1; i<=n; ++i) {
      cnt[i] = 0;
    }
    for(int j=1; j<=m; ++j) {
      if(s[i][j] == '.') {
        continue;
      }
      for(auto p: position[s[i][j] - 'A'][j]) {
        cnt[p]++;
        if(cnt[p] >= k) {
          b = i;
          a = max(a, p);
        }
      }
      position[s[i][j] - 'A'][j].emplace_back(i);
    }
    if(b != 0) {
      break;
    }
  }
  if(b == 0) {
    cout << "-1\n";
  }
  else {
    cout << a << " " << b << "\n";
  }
  return 0;
}