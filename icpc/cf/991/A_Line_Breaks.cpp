#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) {
    int n, m, answer = 0, sum = 0;
    cin >> n >> m;
    string s;
    for(int i=1; i<=n; ++i) {
      cin >> s;
      sum += (int)s.size();
      if(sum > m) {
        continue;
      }
      answer = i;
    }
    cout << answer << "\n";
  }
  return 0;
}