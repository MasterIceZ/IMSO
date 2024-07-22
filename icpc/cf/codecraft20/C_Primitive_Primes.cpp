#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int n, m, p;
  cin >> n >> m >> p;
  pair<int, int> answer;
  for(int i=1, x; i<=n; ++i) {
    cin >> x;
    if(x % p != 0) {
      answer.first = i;
    }
  }
  for(int i=1, x; i<=m; ++i) {
    cin >> x;
    if(x % p != 0) {
      answer.second = i;
    }
  }
  cout << answer.first + answer.second - 2 << "\n";
  return 0;
}