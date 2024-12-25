#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main(int argc, char *argv[]) {
  cin.tie(nullptr)->ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) {
    int n, m, k;
    string s;
    cin >> n >> m >> k >> s;
    int cnt = 0, answer = 0;
    for(int i=0; i<n; ) {
      if(s[i] == '0') {
        cnt++;
        if(cnt == m) {
          for(int j=i; j<min(n, i + k); ++j) {
            s[j] = '1';
          }
          answer++;
          i += k;
          cnt = 0;
        }
        else {
          i++;
        }
      }
      else {
        cnt = 0;
        i++;
      }
    }
    cout << answer << "\n";
  }
  return 0 ;
}